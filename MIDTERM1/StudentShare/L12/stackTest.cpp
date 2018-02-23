#include <iostream>
using namespace std;

#include "stack.h"

int main()
{
	Stack s;
	Node *temp;

	// temp = s.pop();
	s.push("I");
	s.push("caught");
	s.push("you");
	
	// temp = s.pop();

	// cout << "Popped node->item: " << temp->item << endl;
	// cout << "freeing node: " << temp << endl;
	// delete temp;

	//s.push("a");



	s.disp();

	return 0;
}