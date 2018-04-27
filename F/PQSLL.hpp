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

  bool operator<(const listNode & p)const{
		if( this->pri < p.pri ) return true;
		else if( this->pri > p.pri ) return false;
		else if( this->treat < p.treat ) return true;
		return false;
	}
	bool operator>(const listNode & p)const{
		if( this->pri > p.pri ) return true;
		else if( this->pri < p.pri ) return false;
		else if( this->treat > p.treat ) return true;
		return false;
	}
};
class pqList
{
public:
    pqList(){};
    ~pqList(){};
    //circular queue methods
    void enqueue(std::string, int, int);
    void dequeue();
    void printQueue();
protected:
private:
    listNode * head=NULL;
};
#endif
