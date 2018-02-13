#include <iostream>
#include "CommunicationNetwork.cpp"
using namespace std;



int printMenu() {
  string input;

  cout << "======Main Menu======" << endl;
  cout << "1. Build Network" << endl;
  cout << "2. Print Network Path" << endl;
  cout << "3. Transmit Message Coast-To-Coast" << endl;
  cout << "4. Add City" << endl;
  cout << "5. Delete City" << endl;
  cout << "6. Clear Network" << endl;
  cout << "7. Quit" << endl;
  //cout << "Please select an option from the menu by typing the number of the desired choice. Press enter to confirm selction" << endl;
  cin >>  input;
  cout << "You selected " << input << endl;
  return stoi(input);
}

int main() {
  int selection = 0;
  CommunicationNetwork network;
  string previousCity;
  string newCity;

  while (selection != 7)
  {
    selection = printMenu();
    if (selection == 1)
    {
      network.buildNetwork();
    }
    if (selection == 2)
    {
      network.printNetwork();
    }
    if (selection == 3)
    {
      cout << "message sent" << endl;
    }
    if (selection == 4)
    {
      cout << "Enter a city name:";
      cin >> newCity;
      cout << "Enter a previous city name:";
      cin >> previousCity;
      network.addCity(newCity,previousCity);
    }
    if (selection == 5)
    {
      string target;
      cout << "Enter a city name: ";
      cin >> target;
      network.deleteCity(target);
    }
  }

}
