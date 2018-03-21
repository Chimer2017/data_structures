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
                    cout << vertices[i].adj.size() << endl;
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

// void Graph::isAdjacent(string v1, string v2) {
//     vertex first;
//     int firstIndex;
//     // Base case
//     if (v1 == v2)
//       return true;
//     for (int i = 0; i < vertices.size(); i++)
//     {
//       if (vertices[i] == v1)
//       {
//         first = vertices[i];
//         firstIndex = i;
//         break;
//       }
//     }
//
//     // Mark all the vertices as not visited
//     bool *visited = new bool[vertices.size()];
//     for (int i = 0; i < vertices.size(); i++)
//         visited[i] = false;
//
//     // Create a queue for BFS
//     list<vertex> queue;
//
//     // Mark the current node as visited and enqueue it
//     visited[firstIndex] = true;
//     queue.push_back(first);
//
//     // it will be used to get all adjacent vertices of a vertex
//     list<int>::iterator i;
//     vertex tmp;
//
//     while (!queue.empty())
//     {
//         // Dequeue a vertex from queue and print it
//         tmp  = queue.front();
//         queue.pop_front();
//
//         // Get all adjacent vertices of the dequeued vertex s
//         // If a adjacent has not been visited, then mark it visited
//         // and enqueue it
//         for (i = adj[s].begin(); i != adj[s].end(); ++i)
//         {
//             // If this adjacent node is the destination node, then
//             // return true
//             if (*i == d)
//                 return true;
//
//             // Else, continue to do BFS
//             if (!visited[*i])
//             {
//                 visited[*i] = true;
//                 queue.push_back(*i);
//             }
//         }
//     }
//
//     // If BFS is complete without visiting d
//     return false;
//
//
//
// }
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
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
        cout << vertices[i].adj.size() << endl;
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
            cout<<"hello world"<<endl;
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}
