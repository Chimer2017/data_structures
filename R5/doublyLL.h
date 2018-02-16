#ifndef doublyLL_H
#define doublyLL_H

using namespace std;

struct Node {
	int id=-1;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class doublyLL {
	private:
		Node* createNode(int,Node*,Node*);

	public:
		bool insertNodeAtEnd(int);
		doublyLL();	//default constructor
		doublyLL(int);	//overloaded constructor
		~doublyLL();	//destructor
    void displayList();
    void deleteNode();
    Node* head = nullptr;
		Node* tail = nullptr;
};


#endif
