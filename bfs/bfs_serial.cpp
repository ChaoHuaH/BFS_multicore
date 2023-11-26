#include "./utils/graph.h"
#include <iostream>

using namespace std;

vector<int> Graph::BFS(int root, vector<int> &pred)
{
    cout << "## Serial BFS => ";
    // Graph::printAdjList();

    int level = 0;

    for (unsigned int i = 0; i < num_vertices && i < pred.size(); ++i) {
        pred[i] = -1;
    }

    list<int> queue;
    list<int> next_queue;
    queue.push_back(root);
    // pred[root] = root;
    pred[root] = level;

    while (!queue.empty())
    {
        
        level++;
        int n = queue.size();
        for (int i = 0; i < n; i++)
        {

            root = queue.front();
            queue.pop_front();
            // cout << "root: "<< root << ", queue size: " << queue.size() << endl;

            for (list<int>::iterator j=adj[root].begin(); j != adj[root].end(); ++j) {
                if (pred[*j] == -1) 
                {
                    // pred[*j] = root;
                    pred[*j] = level;
                    next_queue.push_back(*j);
                }
            }

        }
        
        // cout << "======== next queue =======" << endl;
        // for (list<int>::iterator i=next_queue.begin(); i != next_queue.end(); ++i) {
        //     cout << *i << " ";
        // }
        // cout << "\n###########################\n" << endl;

        queue.swap(next_queue);
    }
    // cout << endl;
    return pred;
}

