#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
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
  vertex * tmpE = findVertex(endC);
  vertex * tmpS = findVertex(startC);


  if ( tmpS == nullptr || tmpE == nullptr)
    cout << "One or more cities doesn't exist" << endl;
  else if (tmpS->districtID == -1 || tmpE->districtID == -1)
    cout << "Please identify the districts before checking distances" << endl;
  else if(tmpS->districtID != tmpE->districtID)
    cout << "No safe path between cities" << endl;
  else
  {

     // BFT seems to be best option

    // color all vertices red first

    //standard BFT
    vertex * startV;
    // vertex * endV;
    // vertex * midV;
    for ( int i = 0; i < (int)vertices.size(); i++)
    {
        vertices[i].visited = false;
        if (vertices[i].name  == startC)
        {
            startV = &vertices[i];

        }
        // if(vertices[i].name == destination)
        // {
        //     endV = &vertices[i];
        // }
        // if(vertices[i].name == intermediate)
        // {
        //     midV = &vertices[i];
        // }
    }

    cout << startV->name;

    //Now continuing w/ the BFT algo

    startV->visited = true;
    startV->unweightedDistance = 0;

    queue<vertex *> q;

    q.push(startV);

    vertex * n;
    vertex * found = NULL;
    int stat = 0;
    vector<string> hold;
    int disCount = 0;


    //scan the queue now


    while(!q.empty())
    {
        //need these two steps to dequeue
        n = q.front();
        q.pop();

        //scan the adj list of each element

        for ( int x = 0; x < (int)n->adj.size(); x++)
        {
            if (!n->adj[x].v->visited && stat == 0)
            {
                n->adj[x].v->parent = n;
                n->adj[x].v->unweightedDistance = n->unweightedDistance + 1;
                if (n->adj[x].v->name == endC)
                {
                    //return n->adj[x].v;
                    //cout << "found " << endl;
                    stat = 1;
                    found = n->adj[x].v;


                    vertex * current, * tmp;
                    current = found;
                    //cout << "hello" << endl;
                    while (current->name != startC)
                    {
                    tmp = current;
                    //cout << "Current: " << current->name << " " << "Prev: " << current->prev->name << endl;
                    hold.push_back(current->name);

                    current = tmp->parent;
                    }

                    cout << disCount;
                    for (int z = 0; z < hold.size(); z++)
                    {
                      cout << "," << hold[z];
                    }
                    return;
                    
                    //cout << "hello" << endl;
                }
                else
                {
                    n->adj[x].v->visited = true;
                    disCount++;
                    //cout << n->adj[x].v->name << " ";
                    q.push(n->adj[x].v);
                }


            }
        }




    }
   //cout << found->name << endl;







 }
}
void Graph::shortestWeightedPath(string startC, string endC)
{

}


void Graph::DFSLabel(string startC, int distID)
{

}
