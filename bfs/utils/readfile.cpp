#include "readfile.h"

void readData(const char * file_name, unsigned int& num_vertices, unsigned int &num_edges, vector<pair<unsigned int, unsigned int>> &edges)
{
    ifstream inputFile(file_name);

    if(!inputFile.is_open()) {
        cerr << "Can not open file: " << file_name << endl;
        return;
    }
    
    inputFile >> num_vertices >> num_edges;

    unsigned int vertex1, vertex2;
    for (unsigned int i = 0; i < num_edges; i++) {
        inputFile >> vertex1 >> vertex2;
        edges.push_back(make_pair(vertex1, vertex2));
    }

    inputFile.close();

}

void readData(const string & file_name, unsigned int& num_vertices, unsigned int &num_edges, vector<pair<unsigned int, unsigned int>> &edges)
{
    readData(file_name.c_str(), num_vertices, num_edges, edges);
}


void readAnswer(const char * file_name, unsigned int num_vertices, vector<int> &answer)
{
    ifstream inputFile(file_name);

    if (!inputFile.is_open()) {
        cerr << "Can not open file: " << file_name << endl;
        return;
    }

    int index = 0;
    int value;
    while (inputFile >> value) {
        answer[index++] = value;
    }
}

void readAnswer(const string & file_name, unsigned int num_vertices, vector<int> &answer)
{
    readAnswer(file_name.c_str(), num_vertices, answer);
}