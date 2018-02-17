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

int main(int argc, char *argv[]) {
  int selection = 0;
  CommunicationNetwork network;
  string previousCity;
  string newCity;
  int status = 0;


  while (status == 0)
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
      network.transmitMsg(argv[1]);
    }
    if (selection == 4)
    {
      cout << "Enter a city name:";
      cin.ignore();
      getline(cin, newCity);

      cout << "Enter a previous city name:";
      getline(cin, previousCity);
      network.addCity(newCity,previousCity);
    }
    if (selection == 5)
    {
      cin.ignore();
      string target;
      cout << "Enter a city name: ";
      getline(cin,target);
      network.deleteCity(target);
    }
    if (selection == 6)
    {
      network.deleteNetwork();
    }
    if (selection == 7)
    {
      network.~CommunicationNetwork();
      cout << "Goodbye!" << endl;
      status = 1;
    }
  }

}
