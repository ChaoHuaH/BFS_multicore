#include "./utils/graph.h"
#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

vector<int> Graph::BFS(int root, vector<int> &pred)
{
    // cout << "number of threads: " << omp_get_num_threads() << endl;
    int level = 0;

    // #pragma omp parallel shared(pred)
    #pragma omp parallel num_threads(4)
    {
        cout << "number of threads: " << omp_get_num_threads() << " => thread" << omp_get_thread_num() << " " << endl;

        int RR;
        # pragma omp single
        {
            RR = 1;
            cout << " thread: " << omp_get_thread_num() << " init RR = " << RR << endl;
        }
        
        #pragma omp for
        for (int i = 0; i < 8; i++) {
            cout << " thread: " << omp_get_thread_num() << " is processing " << i << endl;
            cout << " thread: " << omp_get_thread_num() << " acquire RR = " << RR << endl;

        }

    }

    return pred;
}

