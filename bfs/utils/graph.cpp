#include "graph.h"

Graph::Graph(int num_vertices)
{
    this->num_vertices = num_vertices;
    adj.resize(num_vertices);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
};

void Graph::printAdjList()
{
    fprintf(stdout, "======== Adjacency List =======\n");
    for (int i = 0; i < adj.size(); i++) {
        fprintf(stdout, "root: %d => ", i);
        for (list<int>::iterator j = adj[i].begin(); j != adj[i].end(); j++) {
            fprintf(stdout, "%d ", *j);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "===============\n\n");
}