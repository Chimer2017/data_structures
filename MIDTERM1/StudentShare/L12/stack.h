#ifndef STACK_H
#define STACK_H
#define DEBUG true

struct Node
{
	string item;
	Node *next;
};

class Stack
{
private:
	Node *top;
	int count;

public:
	Stack(); // constructor declaration
	~Stack();

	bool isEmpty();
	void push( string newItem );
	Node* pop(); // returns and removes the top 
	void disp();

};


#endif