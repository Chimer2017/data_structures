#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "graph.h"



using namespace std;


void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        //cout << "adding " << weight << endl;
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    //cout << "found " << v2 << endl;
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //cout << vertices[i].adj.size() << endl;
                    // //another vertex for edge in other direction
                    // adjVertex av2;
                    // av2.v = &vertices[i];
                    // av2.weight = weight;
                    // vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

int Graph::isAdjacent(string v1, string v2) {
  //out << v1 << "," << v2 << endl;
  int stat = 0;
  for(int i = 0; i < vertices.size(); i++)
  {
      if (vertices[i].name == v1)
      {
        //cout << v1 << " found" << endl;
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
          //cout << vertices[i].adj[j].v->name << " , v2: " << v2 << endl;
          if (vertices[i].adj[j].v->name == v2)
          {
            //cout << "true" << endl;
            stat = 1;
            return 1;

          }

        }

      }
  }

  if (stat == 0)
  {
    //cout << "false" << endl;
    return 0;

  }

}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}



void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        cout<<vertices[i].name<<"-->";
        //cout << vertices[i].adj.size() << endl;
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
          cout<<vertices[i].adj[j].v->name;
          if (j != vertices[i].adj.size()-1)
            cout<<"***";
        }
        cout<<endl;
    }

}
