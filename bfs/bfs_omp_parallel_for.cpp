#include "./utils/graph.h"
#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

vector<int> Graph::BFS(int root, vector<int> &pred)
{
    // cout << "## OpenMP BFS => ";

    int level = 0;
    list<int> queue;
    list<int> next_queue;

    for (unsigned int i = 0; i < num_vertices && i < pred.size(); ++i) {
        pred[i] = -1;
    }

    // pred[root] = root;
    pred[root] = level;
    queue.push_back(root);

    while (!queue.empty())
    {
        
        level++;
        int n = queue.size();

        #pragma omp parallel for
        for (int i = 0; i < n; i++)
        {
            
            int current_root = -1;
            #pragma omp critical
            {
                if (!queue.empty()) {
                    current_root = queue.front();
                    queue.pop_front();
                }
            }

            if (current_root != -1) {
                for (list<int>::iterator j = adj[current_root].begin(); j != adj[current_root].end(); j++)
                {
                    #pragma omp critical
                    {
                        if (pred[*j] == -1) 
                        {
                            // pred[*j] = root;
                            pred[*j] = level;
                            next_queue.push_back(*j);
                        }
                    }
                }
            }
        }

        queue.swap(next_queue);
    }

    return pred;
}

