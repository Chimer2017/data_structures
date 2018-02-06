#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct city{
  string cityName;
  string message;
  city *next;
  city() {};
  city(string initName, city *initNext, string initMessage)
  {
    cityName = initName;
    next = initNext;
    message = initMessage;

  }

};

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
//*************************BUILD NETWORK OPTION 1************************//
city *buildNetwork() {
  string cities[] = {"Los Angeles","Phoenix", "Denver", "Dallas", "St.Louis"
  , "Chicago" , "Atlanta", "Washington, D.C.", "New York", "Boston"};
  city *head, *current, *tmp;
  head = new city(cities[0],nullptr,"");
  current = new city();
  current = head;
  int i = 1;
  while (i < 10)
  {
    tmp = new city(cities[i],nullptr,"");
    current->next = tmp;
    current = tmp;
    i++;
  }
  cout << "===Current Path===" << endl;
  current = head;
  while(current != nullptr)
  {
    cout << current->cityName << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
  cout << "==================" << endl;
  return head;
}
//*************************PRINT NETWORK OPTION 2**********************//
void printPath(city *head) {
  city *current;
  current = new city();
  cout << "===Current Path===" << endl;
  current = head;
  while(current != nullptr)
  {
    cout << current->cityName << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
  cout << "==================" << endl;
}
//*************************ADD CITY OPTION 3**********************//
city *addCity(city *head, city *previous, string cityName) {
  //three use cases

  // add a new networkHead

  // add a new tail

  // insert a city

  return head;
}




int main() {
  int selection = 0;
  city *networkHead;
  string newCity;
  string previousCity;

  while(selection != 5)
  {
      selection = printMenu();
      if (selection == 1)
      {
        networkHead = buildNetwork();
        cout << endl;
      }
      else if (selection == 2)
      {
        printPath(networkHead);
        cout << endl;
      }
      else if (selection == 4)
      {
        cout << "Please input the name of new city you would like to add to the network. Press enter when done." << endl;
        cin >> newCity;
        cout << "Please input the name of the city that your new city will follow. Press enter when done." << endl;
        cin >> previousCity;
        //networkHead = addCity(networkHead,/*SEARCH FUNCTION*/, newCity);
      }
  }


}
