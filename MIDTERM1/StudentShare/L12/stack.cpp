#include <iostream>
using namespace std;

#include "stack.h"

	Stack::Stack()
	{
		top = nullptr;
	} // constructor declaration
	Stack::~Stack()
	{
#if DEBUG
	cout << "destruction.."<< endl;
#endif
	Node *current;
		while( !isEmpty() )
		{
			current = top;
			top = top->next;
#if DEBUG
			cout << "freeing node: " << current << endl;
			delete current;
#endif
		}
	}

	bool Stack::isEmpty()
	{
		if( top == nullptr )
			return true;
		else
			return false;
	}
	void Stack::push( string newItem )
	{
		Node *temp = new Node;
#if DEBUG
		cout << "allocating node: " << temp << endl;
#endif
		temp->item = newItem;

		if( isEmpty() )
		{
			top = temp;
			top->next = nullptr;
		}
		else
		{
			temp->next = top;
			top = temp;
		}


	}
	Node* Stack::pop()
	{
		Node *temp;
		if(!isEmpty())
		{
			temp = top;
			top = top->next;
		}
		else
		{
			cout << "underflow, returning nullptr" << endl;
			temp = nullptr;
		}

		return temp;

	}



	 // returns and removes the top 
	void Stack::disp()
	{
		Node *current = top;
		cout << "Top of the stack: " << endl;
		while( current != nullptr )
		{
			cout << current->item << endl;
			current = current->next;
		}
	}