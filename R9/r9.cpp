#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.cpp"
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
      getline(ss,arr[i],' ');
      i++;

    }
    // for (int j = 0; j < 4; j++)
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
      getline(ss,city,' ');
      int z = 0;
      while(getline(ss,readWeight,' '))
      {
        weight = stoi(readWeight);
        //cout << readWeight << endl;
        cout << city << " " << arr[z] << " " << weight << endl;
        if ( weight > 0)
        {
          cout << "added" << endl;
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
  }

}
int printMenu()
{
  string input;
  cout << "======Main Menu======" << endl;
  cout << "1. Print vertices" << endl;
  //cout << "2. Vertex adjacent" << endl;
  cout << "2. Quit" << endl;
  cin >>  input;
  return stoi(input);
}

int main(int argc, char const *argv[]) {
  string cities[4];
  string filename = "mat.txt";
  Graph net;
  Graph *ptrNet;
  ptrNet = &net;
  readCities(cities, filename);
  for (int i = 0; i < 4; i++)
  {
    net.addVertex(cities[i]);
  }
  readEdge(cities, filename, ptrNet);

  int selection = 0;

  while (selection != 2)
  {
    selection = printMenu();
    if (selection == 1)
    {
      net.displayEdges();
    }
    // if (selection == 2)
    // {
    //   string c1, c2;
    //   int x;
    //   cout << "Enter first city:" << endl;
    //   cin.ignore();
    //   getline(cin,c1);
    //   cout << "Enter second city:" << endl;
    //   cin.ignore();
    //   getline(cin,c2);
    //   net.isAdjacent(c1,c2);
    //   //cout << x << end;
    // }
    if (selection == 2)
    {
      net.~Graph();
      cout << "Goodbye!" << endl;
    }
  }








}
