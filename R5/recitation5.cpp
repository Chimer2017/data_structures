#include <iostream>
#include "doublyLL.cpp"
using namespace std;


int main() {
  doublyLL dll;
  for (int i = 1; i < 22; i++)
  {
    if (i % 4 == 0)
    {
      dll.insertNodeAtEnd(4);
    }
    else
    {
        dll.insertNodeAtEnd(i);
    }
  }
  cout << "Original List" << endl;
  dll.displayList();
  dll.deleteNode();
  dll.deleteNode();
  dll.deleteNode();
  dll.deleteNode();
  dll.deleteNode();

  cout << "Delete List" << endl;
  dll.displayList();
}
