#include <iostream>
using namespace std;

struct amigo {

	string name;
	int age;
};

struct listNode {
	string userName;
	listNode *link;

};


int main()
{
	amigo jose;
	amigo *josePtr;

	josePtr = &jose;

	(*josePtr).name = "Bob";
	(*josePtr).age = 99;
	//derefencing struct with pointer
	//can also use this:

	josePtr->name = "Tom";
	josePtr->age = 70;

	cout << jose.name;
	cout << jose.age;

	/* 
	Dynamically allocated memory:

	stack - where memory lives
	automatic variables get allocated on the stack
	dynamic variables get allocated at run-time and use the heap



	New Operators:

	new:

	int *pl;

	pl = new int;

	delete: deallocates the memory in the heap for that pointer

	delete pl;

	pl = new int;

*/


  // dynamic array with user input length
	int n = 5;
	int *a;

	a = new int[n];  //dynamic array

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int *temp;


	temp = new int[2*n];

	for (int j = 0; j < n; j++)
	{
		temp[j] = a[j];
	}
	
	a = temp;
	delete [] temp;













	return 0;
}