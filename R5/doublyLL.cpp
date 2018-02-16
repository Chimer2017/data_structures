#include <iostream>
#include "doublyLL.h"
using namespace std;



Node *searchList( Node *head ) {
	Node *current;
	current = head;

	while( current!=nullptr )
	{
		if( current->id == 4 )
			return current;
		else
			current = current->next;
	}

	return nullptr;
}

doublyLL::doublyLL() {
  head = nullptr;
  tail = nullptr;

}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

void doublyLL::displayList() {
  Node *current;
  current = head;
  while (current != nullptr)
  {
    cout << current->id << " -> ";
    current = current->next;
  }
  cout << endl;

}

void doublyLL::deleteNode() {
  Node *compare;
  compare = searchList(head);

  /* If node to be deleted is head node */
  if(head == compare)
    head = compare->next;

  /* Change next only if node to be deleted is NOT the last node */
  if(compare->next != nullptr)
    compare->next->prev = compare->prev;

  /* Change prev only if node to be deleted is NOT the first node */
  if(compare->prev != nullptr)
    compare->prev->next = compare->next;

  /* Finally, free the memory occupied by del*/
  delete compare;
}
