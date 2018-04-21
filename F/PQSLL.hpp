#ifndef PQLIST_H
#define PQLIST_H
#include <iostream>
using namespace std;




struct listNode {
  string name;
  int pri;
  int treat;
  listNode * next = NULL;
  listNode(){};
  listNode(string n, int p, int t)
  {
    name = n;
    pri = p;
    treat = t;
    next = NULL;
  }


};




class pqList
{
public:
    pqList(){

    };
    ~pqList(){};
    //circular queue methods
    void enqueue(std::string, int, int);
    void dequeue();
    void printQueue();
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty


protected:
private:
    listNode * head;
};

#endif
