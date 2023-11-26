#include <string>
#include "./utils/graph.h"
#include "./utils/readfile.h"
#include "./utils/validate.h"


int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] <<  " <inputFile>" << endl;
        return 1;
    }

    unsigned int num_vertices, num_edges;
    vector<pair<unsigned int, unsigned int>> edges;
    readData(argv[1], num_vertices, num_edges, edges);

    // cout << "Edges:" << endl;
    // for (const auto& edge : edges) {
    //     cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    // }
    
    Graph g(num_vertices);
    for (unsigned int i = 0; i < num_edges; i++) {
        g.addEdge(edges[i].first, edges[i].second);
    }

    vector<int> pred;
    pred.resize(num_vertices + 1, -1);
    int root;


    // cout << "============= Format =============" << endl;
    // cout << "[... level of index i + root]" << endl << endl;


    if (argc > 2) {
        vector<int> answer;
        answer.resize(num_vertices + 1, -1);
    
        string answer_root;
        for (int i = 0; i < num_vertices; i++) {
            
            root = i; 
            pred[num_vertices] = root;
            g.BFS(root, pred);

            answer_root = string(argv[2]) + to_string(i) + ".ans";
            readAnswer(answer_root, num_vertices, answer);

            // for (int i = 0; i < pred.size(); i++) {
            //     cout << pred[i] << " ";
            //     }
            // cout << endl;
            // for (int i = 0; i < num_vertices + 1; i++) {
            //     cout << answer[i] << " ";
            //     }
            // cout << endl;
            cout << "Root " << i << ": ";
            isCorrect(answer, pred);
        }
        cout << endl;
    }

    return 0;
}