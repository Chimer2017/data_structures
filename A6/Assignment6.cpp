#include <iostream>
#include <sstream>
#include <fstream>
#include "MovieTree.cpp"
using namespace std;




int printMenu() {
  int value;
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Rent a movie" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Delete a movie" << endl;
  cout << "5. Count the movies" << endl;
  cout << "6. Quit" << endl;
  cin >> value;
  return value;

}

int main() {
  int selection;
  int status = 0;
  // print menu

  string line;
  string tempRank;
  string tempTitle;
  string tempYear;
  string tempQuantity;
  char tempFirstLetter;
  MovieTree tree;
  string filename = "test.txt";
  ifstream ff;
  ff.open(filename);
  if (ff.is_open())
  {
    while(getline(ff,line))
    {
      stringstream ss(line);
      getline(ss,tempRank,',');
      getline(ss,tempTitle,',');
      getline(ss,tempYear,',');
      getline(ss,tempQuantity);

      tree.addMovieNode(stoi(tempRank),tempTitle,stoi(tempYear),stoi(tempQuantity));




    }
  }
  else
  {
    ff.close();
    cout << "File did not open" << endl;
  }
  while (status == 0)
  {
    selection = printMenu();
    if (selection == 3)
    {
      tree.printMovieInventory();
    }
    if (selection == 6)
    {
      status = 1;
      cout << "Goodbye!" << endl;
    }
  }





}
