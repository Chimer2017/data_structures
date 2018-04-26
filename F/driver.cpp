#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <time.h>
#include "PQSLL.cpp"
#include "PQH.cpp"
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
    cout <<readCount <<  ": about tp add\n";
    tmp->enqueue(n,stoi(p),stoi(t));
    cout << n << " " << readCount << ": added\n";
  }
  delete tmp;
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
  }
};
int main() {

  string filename = "test.csv";
  int rows = 880;
  ////Linked List Object Init and Run/////////**************************
  // pqList qList;
  // pqList * qListPtr;
  // qListPtr = &qList;
  // double tstart = clock();
  // readFileSLL(qListPtr,filename,rows);
  // //qList.printQueue();
  // qList.dequeue();
  // double tend = clock();
  //
  // cout << tstart - tend << endl;
  //




  /////////Min Heap Object Init and Run////////////////////////////*******

  mh qHeap = mh(rows);
  node *arrPtr = readFileHeap(filename,rows);
  // for (int i = 0; i < rows;i++)
  // {
  //   cout << arrPtr[i].name << " " << arrPtr[i].pri << " " << arrPtr[i].treat << endl;
  // }
  double tstart = clock();
  qHeap.enqueueH(arrPtr);
  qHeap.dequeueH();
  double tend = clock();
  cout << (tend-tstart)/CLOCKS_PER_SEC << endl;


// //////STL Heap Object Init and Run *************************************
// priority_queue <stdNode, vector<stdNode>, order > pq;
// stdNode *stdArrPtr = readFileSTL(filename, rows);
// int index = 0;
// while (index < rows)
// {
//   pq.push(stdArrPtr[index]);
//   index++;
// }
//
//
// while (pq.empty() == false)
// {
//   cout << pq.top().name << " " << pq.top().pri << " " << pq.top().treat << endl;
//   pq.pop();
// }
//
//











}
