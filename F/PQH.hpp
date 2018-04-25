#ifndef MH_H
#define MH_H
#include <iostream>
#include <climits>

using namespace std;



struct node {
  string name;
  int pri;
  int treat;
  node(){};
  node(string n, int p,int t)
  {
    name = n;
    pri = p;
    treat = t;
  }
};


class mh {
  node *harr;
  int arraySize;
  int heapSize;
public:
  mh(){};
  mh(int);
  void minHeapify(int);
  int left(int i) {return (2*i + 1);}
  int right(int i) {return (2*i + 2);}
  int parent(int i) {return ((i-1)/2);}
  void dequeueH();
  void enqueueH(node[]);
};
#endif
