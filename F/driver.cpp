#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <time.h>
#include "PQSLL.cpp"
#include "PQH.cpp"
#include <math.h>

using namespace std;
struct stdNode {
  string name;
  int pri;
  int treat;
  stdNode(){};
  stdNode(string n, int p, int t)
  {
    name = n;
    pri = p;
    treat = t;
  }
};

void readFileSLL(pqList * tmp, string filename, int r)
{
  string line;
  string n,p,t;
  ifstream ff;
  ff.open(filename);
  getline(ff,line);
  int readCount = 0;
  while (readCount < r)
  {
    readCount++;
    getline(ff,line);
    stringstream ss(line);
    getline(ss,n,',');
    getline(ss,p,',');
    getline(ss,t);
    //cout <<readCount <<  ": about tp add\n";
    tmp->enqueue(n,stoi(p),stoi(t));
  //  cout << n << " " << readCount << ": added\n";
  }

}
node * readFileHeap(string filename,int r)
{
  node * arr = new node[r];
  ifstream ff;
  string line,n,p,t;
  ff.open(filename);
  getline(ff,line);
  int readCount = 0;
  int index = 0;
  while(readCount < r)
  {
    readCount++;
    getline(ff,line);
    stringstream ss(line);
    getline(ss,n,',');
    getline(ss,p,',');
    getline(ss,t);
    node temp = node(n,stoi(p),stoi(t));
    arr[index] = temp;
    index++;
  }

  return arr;


}
stdNode * readFileSTL(string filename,int r)
{
  stdNode * arr = new stdNode[r];
  ifstream ff;
  string line,n,p,t;
  ff.open(filename);
  getline(ff,line);
  int readCount = 0;
  int index = 0;
  while(readCount < r)
  {
    readCount++;
    getline(ff,line);
    stringstream ss(line);
    getline(ss,n,',');
    getline(ss,p,',');
    getline(ss,t);
    stdNode temp = stdNode(n,stoi(p),stoi(t));
    arr[index] = temp;
    index++;
  }

  return arr;


}
struct order
{
  bool operator() (stdNode const &a, stdNode const &b)
  {
    if (a.pri != b.pri)
    {
      return a.pri > b.pri;
    }
    else if (a.pri == b.pri)
    {
      return a.treat > b.treat;
    }
    return false;
  }
};

double variance(double a[], double n)
{
    // Compute mean (average of elements)
    double sum = 0;
    for (int i=0; i<n; i++)
    {
      //cout << a[i] << endl;
      sum += a[i];
    }


    double mean = (double)sum/(double)n;

    // Compute sum squared differences with
    // mean.
    double sqDiff = 0;
    for (int i=0; i<n; i++)
        sqDiff += (a[i] - mean)*(a[i] - mean);

    //cout << sqDiff/n << endl;
    return sqDiff/(double)n;
}

double standardDeviation(double arr[], int n)
{
      return sqrt(variance(arr, n));
}


int main() {
  int status =0;
  while(status == 0)
  {
    int rows;
    string filename = "test.csv";
    cout << "Rows: ";
    cin >> rows;
    if ( rows == 000)
      return 0;
    double tstart;
    double tend;
    double arraySLLEnqueue[500];
    double arraySLLDequeue[500];

    for (int i = 0; i < 500; i++)
    {
      pqList qList;
      pqList * qListPtr;
      qListPtr = &qList;
      tstart = clock();
      readFileSLL(qListPtr,filename,rows);
      tend = clock();
      //cout << "SLL Implementation Enqueue: " << (tend - tstart) / CLOCKS_PER_SEC << endl;
      arraySLLEnqueue[i] = ((double)tend - (double)tstart) / CLOCKS_PER_SEC;
      //qList.printQueue();
      tstart = clock();
      qList.dequeue();
      tend = clock();
      arraySLLDequeue[i] = (tend - tstart) / CLOCKS_PER_SEC;
      //cout << "SLL Implementation Dequeue: " << (tend - tstart) / CLOCKS_PER_SEC << endl;
    }
    double sumE = 0;
    double sumD = 0;
    for (int i=0; i<500; i++)
    {
      sumE += arraySLLEnqueue[i];
      sumD += arraySLLDequeue[i];
    }
    //cout << sumD <<" " << sumE << endl;
    double meanE = (double)sumE/(double)500;
    double meanD = (double)sumD/(double)500;
    double stdSLLEnqueue = standardDeviation(arraySLLEnqueue,500);
    double stdSLLDequeue = standardDeviation(arraySLLDequeue,500);

    cout << "SLL Enqueue Mean: " << meanE << " Standard Deviation: " << stdSLLEnqueue << endl;
    cout << "SLL Dequeue Mean: " << meanD << " Standard Deviation: " << stdSLLDequeue << endl;



    ////Linked List Object Init and Run/////////**************************


    // //////STL Heap Object Init and Run *************************************
    priority_queue <stdNode, vector<stdNode>, order > pq;
    stdNode *stdArrPtr = readFileSTL(filename, rows);

    double arraySTLEnqueue[500];
    double arraySTLDequeue[500];

    for (int i = 0; i < 500; i++)
    {
      int index = 0;
      tstart = clock();
      while (index < rows)
      {
        pq.push(stdArrPtr[index]);
        index++;
      }
      tend = clock();
      arraySTLEnqueue[i] = (tend - tstart) / CLOCKS_PER_SEC;
      //cout << "STL Implementation Enqueue: " << (tend - tstart) / CLOCKS_PER_SEC << endl;
      tstart = clock();
      while (pq.empty() == false)
      {
        //cout << pq.top().name << " " << pq.top().pri << " " << pq.top().treat << endl;
        pq.pop();
      }
      tend = clock();
      arraySTLDequeue[i] = (tend - tstart) / CLOCKS_PER_SEC;
    }
    //cout << "STL Implementation Dequeue: " << (tend - tstart) / CLOCKS_PER_SEC << endl;
    sumE = 0;
    sumD = 0;
    for (int i=0; i<500; i++)
    {
      sumE += arraySTLEnqueue[i];
      sumD += arraySTLDequeue[i];
    }
    //cout << sumD <<" " << sumE << endl;
    meanE = (double)sumE/(double)500;
    meanD = (double)sumD/(double)500;
    double stdSTLEnqueue = standardDeviation(arraySTLEnqueue,500);
    double stdSTLDequeue = standardDeviation(arraySTLDequeue,500);

    cout << "STL Enqueue Mean: " << meanE << " Standard Deviation: " << stdSTLEnqueue << endl;
    cout << "STL Dequeue Mean: " << meanD << " Standard Deviation: " << stdSTLDequeue << endl;





    /////////Min Heap Object Init and Run////////////////////////////*******

    mh qHeap = mh(rows);
    node *arrPtr = readFileHeap(filename,rows);

    double arrayHEnqueue[500];
    double arrayHDequeue[500];

    for (int i = 0; i < 500; i++)
    {
      tstart = clock();
      qHeap.enqueueH(arrPtr);
      tend = clock();
      arrayHEnqueue[i] = (tend - tstart) / CLOCKS_PER_SEC;
      //cout << "Heap Implementation Enqueue: " << (tend-tstart)/CLOCKS_PER_SEC << endl;

      //tstart = clock();
      tstart = clock();
      qHeap.dequeueH();
      tend = clock();
      arrayHDequeue[i] = (tend - tstart) / CLOCKS_PER_SEC;
      //cout << "Heap Implementation Dequeue: " << (tend-tstart)/CLOCKS_PER_SEC << endl;
      // delete [] arrPtr;
      // qHeap.~mh();
    }
    sumE = 0;
    sumD = 0;
    for (int i=0; i<500; i++)
    {
      sumE += arrayHEnqueue[i];
      sumD += arrayHDequeue[i];
    }
    //cout << sumD <<" " << sumE << endl;
    meanE = (double)sumE/(double)500;
    meanD = (double)sumD/(double)500;
    double stdHEnqueue = standardDeviation(arrayHEnqueue,500);
    double stdHDequeue = standardDeviation(arrayHDequeue,500);

    cout << "Heap Enqueue Mean: " << meanE << " Standard Deviation: " << stdHEnqueue << endl;
    cout << "Heap Dequeue Mean: " << meanD << " Standard Deviation: " << stdHDequeue << endl;
}












}
