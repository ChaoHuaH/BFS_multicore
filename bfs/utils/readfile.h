#ifndef READFILE_H
#define READFILE_H

#include <vector>
#include <utility>  // For std::pair
#include <fstream>  // For file operations
#include <iostream> // For std::cerr
#include "readfile.h"

using namespace std;

void readData(const char * file_name, unsigned int& num_vertices, unsigned int &num_edges, vector<pair<unsigned int, unsigned int>> &edges);
void readData(const string & file_name, unsigned int& num_vertices, unsigned int &num_edges, vector<pair<unsigned int, unsigned int>> &edges);
void readAnswer(const char * file_name, unsigned int num_vertices, vector<int> &answer);
void readAnswer(const string & file_name, unsigned int num_vertices, vector<int> &answer);

#endif // READFILE_H