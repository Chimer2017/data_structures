#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
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
// int isAdjacent(string v1, string v2) {
//   //out << v1 << "," << v2 << endl;
//   int stat = 0;
//   for(int i = 0; i < vertices.size(); i++)
//   {
//       if (vertices[i].name == v1)
//       {
//         //cout << v1 << " found" << endl;
//         for(int j = 0; j < vertices[i].adj.size(); j++)
//         {
//           //cout << vertices[i].adj[j].v->name << " , v2: " << v2 << endl;
//           if (vertices[i].adj[j].v->name == v2)
//           {
//             //cout << "true" << endl;
//             stat = 1;
//             return 1;
//
//           }
//
//         }
//
//       }
//   }
//
//   if (stat == 0)
//   {
//     //cout << "false" << endl;
//     return 0;
//
//   }
//
// }
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
        cout<<vertices[i].districtID << ":" << vertices[i].name<<"-->";
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

vertex * Graph::findVertex(string city)
{
  	int i=0;
  	while (i < vertices.size()) {
  		if (vertices[i].name == city) {
  			return &vertices[i];
  		}
  		i++;
  	}
  	return nullptr;

}

void Graph::assignDistricts()
{

  int districtCount = 1;
  for (int z = 0; z < 10; z++)
  {
  if (vertices[z].districtID != -1)
    continue;

  string src;
  src = vertices[z].name;


	// s helps determine the depth first traversal
	stack<vertex*> s;
	// path will be the path taken from 'src' to 'dst'
	vector<vertex*> path;

	// make sure the vertices have 'visited' set to false
	for(int i = 0; i < vertices.size(); i++)
        vertices[i].visited = false;

	// push the starting node 'src'
	s.push(findVertex(src));
	// main DFS loop
	while( !s.empty() ){
		vertex * cur = s.top();
		s.pop();

		if( !cur->visited ){
			// visit current node if it was unvisited,
			// then add it to the tentative path
			cur->visited = true;
			path.push_back(cur);
			// while the last node in 'path' does not have an
			// edge to the current node erase it from the path
			while(path.size() > 1){
				bool isin = false;
				int idx = path.size()-2;
				for(int i = 0; i < path[path.size()-2]->adj.size(); i++){
					if( path[idx]->adj[i].v==path.back() ) isin = true;
				}
				if(!isin)
					path.erase(path.begin()+idx);
				else
					break;
			}
			// when you reach the 'dst', terminate depth first traversal
			// push all of current's neighbors to the stack (DFS step)
			for(int i = 0; i < cur->adj.size(); ++i)
				s.push(cur->adj[i].v);
		}
	}

	// print the path from 'src' to 'dst'
	cout << endl << "Path: ";
	for(int i = 0; i < path.size()-1; i++)
  {
    cout << path[i]->name << "-->";
    path[i]->districtID = districtCount;
    for ( int x = 0; x < path[i]->adj.size(); x++)
    {
      path[i]->adj[x].v->districtID = districtCount;
    }


  }
	path.back()->districtID = districtCount;
  districtCount++;




  }
}

void Graph::shortestPath(string startC, string endC)
{
  vertex *tmpS;
  vertex *tmpE;

  tmpS = findVertex(startC);
  tmpE = findVertex(endC);

  if ( tmpS == nullptr || tmpE == nullptr)
    cout << "One or more cities doesn't exist" << endl;
  else if (tmpS->districtID == -1 || tmpE->districtID == -1)
    cout << "Please identify the districts before checking distances" << endl;
  else if(tmpS->districtID != tmpE->districtID)
    cout << "No safe path between cities" << endl;
  else
  {

    // q helps determine the breadth first traversal
    queue<vertex*> que;
    // maxAdj contains a running list of the 'maximum adjacent' nodes
    vector<vertex*> maxAdj;

    // make sure the vertices have 'visited' set to false
    for(int i = 0; i < vertices.size(); i++)
          vertices[i].visited = false;

      // handle the starting node
    que.push(tmpS);
    vertex * cur = que.front();
    cur->visited = true;
    cout << cur->name << ' ';
    int max = cur->adj.size();
    maxAdj.push_back(cur);

    // main loop
    while( !que.empty() ) {
      cur = que.front();
      que.pop();

      // for each of the current node's unvisited
      // neighbors, push, print, and visit
      for(int i = 0; i < cur->adj.size(); ++i){
        if(cur->adj[i].v->visited == false){
          que.push(cur->adj[i].v);
          cur->adj[i].v->visited = true;
          cout << cur->adj[i].v->name << ' ';
          int size = cur->adj[i].v->adj.size();
          // if a node has more adjacencies than the current max,
          // clear maxAdj and push back the new max adjacent node
          if(size > max){
            max = size;
            maxAdj.clear();
            maxAdj.push_back(cur->adj[i].v);
          }
          // otherwise if a node has the same number of adjacencies
          // as the current max, simply add it to the end of the
          // maxAdj vector
          else if(size==max)
            maxAdj.push_back(cur->adj[i].v);
        }
      }
    }

    // print final list of 'maximum adjacent' nodes
    cout << endl << "MaxAdj: ";
    for(int i = 0; i < maxAdj.size(); ++i)
      cout << maxAdj[i]->name << ' ';
    cout << endl;
  }



}

void Graph::shortestWeightedPath(string startC, string endC)
{

}


void Graph::DFSLabel(string startC, int distID)
{

}
