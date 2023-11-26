#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class Graph 
{
    
    int num_vertices; // number of vertices
    vector< list<int> > adj; // adjacency list

public:
    Graph(int num_vertices);
    void addEdge(int v, int w);
    void printAdjList();
    vector<int> BFS(int root, vector<int> &pred);
    

};

#endif // GRAPH_H