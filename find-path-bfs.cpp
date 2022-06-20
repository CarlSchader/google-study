#include "create-adjacency-list.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > *al;
int componentCount;
int *parents;
bool *seen;

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << ' ';
    }
}

template<typename T>
void printArray(T *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

void bfs(int node) {
    queue<int> bfsQueue;
    seen[node] = true;
    parents[node] = -1;
    bfsQueue.push(node);
    int neighbor;
    while (!bfsQueue.empty()) {
        node = bfsQueue.front();
        bfsQueue.pop();
        for (int i = 0; i < al->at(node).size(); i++) {
            neighbor = al->at(node).at(i);
            if (!seen[neighbor]) {
                seen[neighbor] = true;
                parents[neighbor] = node;
                bfsQueue.push(neighbor);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return -1;
    }
    int startNode = stoi(argv[1]);
    int endNode = stoi(argv[2]);
    al = create_adjacency_list(cin);
    const int node_count = al->size();
    seen = new bool[node_count];
    parents = new int[node_count];
    fill(seen, seen + node_count, false);
    fill(parents, parents + node_count, -1);

    bfs(startNode);

    string path = "";
    int current = endNode;
    while (current != -1) {
        string next(path);
        path = to_string(current);
        path.append("->");
        path.append(next);
        current = parents[current];
    }

    cout << path.substr(0, path.size() - 2) << endl;

    return 0;
}