#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.cpp"
using namespace std;

void readCities(string arr[], string filename)
{
  ifstream ff;
  ff.open(filename);
  if (ff.is_open())
  {
    string line;
    getline(ff,line);
    int i = 0;
    while(getline(ff,line))
    {
      stringstream ss(line);
      getline(ss,arr[i],',');
      i++;

    }
    // for (int j = 0; j < 15; j++)
    // {
    //   cout << arr[j] << endl;
    // }

  }
  else
  {
    cout << "file did not open" << endl;
    ff.close();
  }

}
void readEdge(string arr[], string filename, Graph *gr)
{
  ifstream ff;
  ff.open(filename);
  if (ff.is_open())
  {
    string line;
    string city;
    string readWeight;
    int weight;
    getline(ff,line);
    while(getline(ff,line))
    {
      stringstream ss(line);
      getline(ss,city,',');
      int z = 0;
      while(getline(ss,readWeight,','))
      {
        weight = stoi(readWeight);
        //cout << readWeight << endl;
        //cout << city << " " << arr[z] << " " << weight << endl;
        if ( weight > 0)
        {
          //cout << "added" << endl;
          gr->addEdge(city,arr[z],weight);
        }

        z++;

      }
      //cout << "next"<< endl;
    }


  }
  else
  {
    ff.close();
    cout << "file did not open add edge" << endl;
  }


}
int printMenu()
{
  string input;
  cout << "======Main Menu======" << endl;
  cout << "1. Print vertices" << endl;
  cout << "2. Find districts" << endl;
  cout << "3. Find shortest path" << endl;
  cout << "4. Find shortest weighted path" << endl;
  cout << "5. Quit" << endl;
  cin >>  input;
  return stoi(input);
}
int main(int argc, char *argv[]) {
  string cities[15];
  string filename = "text.txt";
  Graph net;
  Graph *ptrNet;
  ptrNet = &net;
  readCities(cities, filename);
  for (int i = 0; i < 15; i++)
  {
    net.addVertex(cities[i]);
  }
  readEdge(cities, filename, ptrNet);

  int selection = 0;

  while (selection != 5)
  {
    selection = printMenu();
    if (selection == 1)
    {
      net.displayEdges();
    }
    if (selection == 2)
    {
      net.assignDistricts();

    }
    if (selection == 3)
    {
      string c1, c2;
      cout << "Enter a starting city:" << endl;
      cin.ignore();
      getline(cin,c1);
      cout << "Enter an ending city:" << endl;
      getline(cin,c2);
      net.shortestPath(c1,c2);

    }
    if (selection == 4)
    {
      string c1, c2;
      cout << "Enter a starting city:" << endl;
      cin.ignore();
      getline(cin,c1);
      cout << "Enter an ending city:" << endl;
      getline(cin,c2);
      net.shortestWeightedPath(c1,c2);


    }
    if (selection == 5)
    {
      net.~Graph();
      delete ptrNet;
      cout << "Goodbye!" << endl;
    }
  }




}
