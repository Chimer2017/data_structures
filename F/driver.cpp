#include <iostream>
#include <fstream>
#include <sstream>
#include "PQSLL.cpp"
#include "PQH.cpp"
using namespace std;


void readFileSLL(pqList * tmp, string filename, int r)
{
  string line;
  string n,p,t;
  ifstream ff;
  ff.open(filename);
  getline(ff,line);
  int readCount = 0;
  int rows = r;
  while (readCount < rows)
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




















int main() {

  string filename = "test.csv";
  int rows = 10;
  ////Linked List Object Init and Run/////////**************************
  pqList qList;
  pqList * qListPtr;
  qListPtr = &qList;

  readFileSLL(qListPtr,filename,rows);
  qList.printQueue();
  qList.dequeue();





  /////////Min Heap Object Init and Run////////////////////////////*******

  mh qHeap = mh(880);
  node *arrPtr = readFileHeap(filename,rows);













}
