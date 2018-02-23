#include <iostream>

using namespace std;
#include "SLL.h"

int main()
{
	SLL l;

	string arr[] = {"jeden","dwa","trzy"};

	int arrLen = 3;

	for( int i = 0; i<arrLen; i++ )
		l.growList( arr[i] );

	l.displayList();

	return 0;
}