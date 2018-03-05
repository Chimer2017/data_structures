#include <iostream>
#include "BST.cpp"
using namespace std;


int main() {
  cout << "Hello" << endl;
  BST *object1= new BST(7);
  object1->insertNode(5);
  object1->insertNode(4);
  object1->insertNode(1);
  object1->insertNode(2);
  object1->insertNode(6);
  object1->insertNode(10);
  object1->insertNode(0);
  object1->insertNode(1);
  object1->insertNode(12);
  object1->insertNode(13);

  object1->printTree();
  cout << endl;

  if (object1->searchKey(10))
  {
    cout << 10 << " has been found" << endl;
  }
  else
  {
    cout << 10 << " has not been found" << endl;
  }

  if (object1->searchKey(25))
  {
    cout << 25 << " has been found" << endl;
  }
  else
  {
    cout << 25 << " has not been found" << endl;
  }





}
