#include "create-adjacency-list.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DELIMETER " "

template<typename T>
void printVec(vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << ' ';
    }
}

vector<vector<int> > *create_adjacency_list(istream& stream) {
    string input;
    getline(stream, input);
    const int nodes = stoi(input);
    vector<vector<int> > *al = new vector<vector<int> >;

    int currentIndex;
    int nextIndex;
    for (int i = 0; i < nodes; i++) {
        currentIndex = 0;
        nextIndex = 0;
        al->push_back(vector<int>());
        getline(stream, input);
        int length = input.length();
        while (nextIndex != string::npos) {
            nextIndex = input.find(DELIMETER, currentIndex);
            if (nextIndex == string::npos) {
                al->at(i).push_back(stoi(input.substr(currentIndex, length - currentIndex)));
            } else {
                al->at(i).push_back(stoi(input.substr(currentIndex, nextIndex - currentIndex)));
            }
            currentIndex = nextIndex + 1;
        }
    }

    return al;
}

// int main() {
//     vector<vector<int> > *al = create_adjacency_list(cin);
//     for (int i = 0; i < al->size(); i++) {
//         printVec(al->at(i));
//         cout << endl;
//     }
//     return 0;
// }
