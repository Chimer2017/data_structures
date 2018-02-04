#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int printMenu() {
  string input;

  cout << "======Main Menu======" << endl;
  cout << "1. Build Network" << endl;
  cout << "2. Print Network Path" << endl;
  cout << "3. Transmit Message Coast-To-Coast" << endl;
  cout << "4. Add City" << endl;
  cout << "5. Quit" << endl;

  cout << endl << endl;
  cout << "Please select an option from the menu by typing the number of the desired choice. Press enter to confirm selction" << endl;
  cin >>  input;
  cout << "You selected " << input << endl;
  return stoi(input);
}



int main() {
  int selection = printMenu();
  while(selection != 5)
  {
      selection = printMenu();
      
  }


}
