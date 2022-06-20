#include "create-adjacency-list.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > *al;
int componentCount;
int *components;
bool *seen;

void dfs(int node) {
    seen[node] = true;
    components[node] = componentCount;
    int neighbor;
    for (int i = 0; i < al->at(node).size(); i++) {
        neighbor = al->at(node).at(i);
        if (!seen[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    al = create_adjacency_list(cin);
    const int node_count = al->size();
    components = new int[node_count];
    seen = new bool[node_count];

    componentCount = 0;
    for (int i = 0; i < node_count; i++) {
        if (!seen[i]) {
            dfs(i);
            componentCount++;
        }
    }

    cout << componentCount << endl;
    return 0;
}