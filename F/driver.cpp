#include <iostream>
#include <fstream>
#include <sstream>
#include "PQSLL.cpp"
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
    getline(ss,t,',');
    cout <<readCount <<  ": about tp add\n";
    tmp->enqueue(n,stoi(p),stoi(t));
    cout << n << " " << readCount << ": added\n";
  }
}


int main() {

  string filename = "test.csv";
  ////Linked List Object Init and Run/////////
  pqList qList;
  pqList * qListPtr;
  qListPtr = &qList;
  int rows = 10;
  readFileSLL(qListPtr,filename,rows);
  //qList.printQueue();
  qList.dequeue();












}
