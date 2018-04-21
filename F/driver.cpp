#include <iostream>
#include <fstream>
#include <sstream>
#include "PQSLL.cpp"
using namespace std;


void readFileSLL(pqList * tmp, string filename)
{
  string line;
  string n,p,t;
  ifstream ff;
  ff.open(filename);
  getline(ff,line);
  int readCount = 0;
  int rows = 200;
  while (readCount < rows)
  {
    readCount++;
    getline(ff,line);
    stringstream ss(line);
    getline(ss,n,',');
    getline(ss,p,',');
    getline(ss,t,',');
    tmp->enqueue(n,stoi(p),stoi(t));
  }
}


int main() {

  string filename = "test.csv";
  ////Linked List Object Init/////////
  pqList qList;
  pqList * qListPtr;
  qListPtr = &qList;
  readFileSLL(qListPtr,filename);
  qList.printQueue();












}
