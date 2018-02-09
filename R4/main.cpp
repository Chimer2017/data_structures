#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


struct node {
  int data;
  node *next;
  node() {};
  node(int initData, node *initNext)
  {
    data = initData;
    next = initNext;
  };
};

void insertAfter( node *prevNode, int x ){
	// Create new node
	node *tmp;
  tmp = new node(x, prevNode->next);
	prevNode->next = tmp;
  tmp = nullptr;

}

int main() {

  int dataArray[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};//20
  node *head, *current, *tmp, *prev;
  head = new node(dataArray[0],nullptr);
  current = new node();
  current = head;


  int i = 1;
  while (i < 19)
  {
    tmp = new node(dataArray[i],nullptr);
    current->next = tmp;
    current = tmp;
    i++;
  }
  cout << "Original List" << endl;
  current = head;
  while(current != nullptr)
  {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
  cout << "------------------------" << endl;
  current = head;
  while(current != nullptr)
  {
    //cout << current->data << " -> ";
    if ((current->data)%2 == 0)
    {
      prev = current;
      current = current->next;
      insertAfter(prev,99);

    }
    else
    {
      current = current->next;
    }

  }
  cout << "Insert List" << endl;
  current = head;
  while(current != nullptr)
  {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;






}
