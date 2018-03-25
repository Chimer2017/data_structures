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
  }


}
int printMenu()
{
  string input;
  cout << "======Main Menu======" << endl;
  cout << "1. Print vertices" << endl;
  cout << "2. Vertex adjacent" << endl;
  cout << "3. Quit" << endl;
  cin >>  input;
  return stoi(input);
}
int main(int argc, char *argv[]) {
  string cities[15];
  string filename = "test.txt";
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

  while (selection != 3)
  {
    selection = printMenu();
    if (selection == 1)
    {
      net.displayEdges();
    }
    if (selection == 2)
    {
      string c1, c2;
      int x;
      cout << "Enter first city:" << endl;
      cin.ignore();
      getline(cin,c1);
      cout << "Enter second city:" << endl;
      getline(cin,c2);
      if (net.isAdjacent(c1,c2)> 0)
        cout << "true" << endl;
      else
        cout << "false" << endl;
      //cout << x << end;
    }
    if (selection == 3)
    {
      net.~Graph();
      delete ptrNet;
      cout << "Goodbye!" << endl;
    }
  }




}
