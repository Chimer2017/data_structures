#include <iostream>
#include "Queue.cpp"
using namespace std;


int printMenu() {
  string input;

  cout << "======Main Menu======" << endl;
  cout << "1. Enqueue word" << endl;
  cout << "2. Dequeue word" << endl;
  cout << "3. Print queue" << endl;
  cout << "4. Enqueue sentence" << endl;
  cout << "5. Quit" << endl;
  //cout << "Please select an option from the menu by typing the number of the desired choice. Press enter to confirm selction" << endl;
  cin >>  input;
  return stoi(input);
}


int main() {
  int selection = 0;
  int status = 0;
  while (status == 0)
  {
    selection = printMenu();
  }
}
