#include "validate.h"

bool isCorrect(vector<int> &answer, vector<int> &pred) 
{
    if (answer.size() != pred.size()) {
        cout << "WRONG! size of answer is different from pred: " << answer.size() << " vs. " << pred.size() << endl;
        return false;
    }

    for (int i = 0; i < answer.size(); i++ ) {
        if (answer[i] != pred[i]) {
            cout << "WRONG! index: " << i << " (answer: " << answer[i] << " vs. pred: " << pred[i] << ")"<< endl;
            return false;
        }
    }
    cout << "CORRECT!!!" << endl;
    return true;
}