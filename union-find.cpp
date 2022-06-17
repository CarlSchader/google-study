#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T, typename containerType>
class union_find {
    private:
    unordered_map<T, int> ids;
    int *parents;
    int *sizes;
    
    public:
    union_find(containerType container) {
        int containerSize = container.size();
        if (containerSize < 0) {
            throw invalid_argument("container must have positive or zero length");
        }

        ids = unordered_map<T, int>();
        parents = new int[containerSize];
        sizes = new int[containerSize];
        int groupId = 0;
        for (const auto& elem : container) {
            ids[elem] = groupId;
            parents[groupId] = groupId;
            sizes[groupId] = 1;
            groupId++;
        }
    }

    int find(T x) {
        int root = ids[x];
        while (root != parents[root]) {
            root = parents[root];
        }

        // path compression
        int next;
        int current = ids[x];
        while (current != parents[current]) {
            next = parents[current];
            parents[current] = root;
            current = next;
        }

        return root;
    }

    void union_elems(T x, T y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            parents[rooty] = rootx;
            sizes[rootx] += sizes[rooty];
        }
    }

    int size(T x) {
        return sizes[find(x)];
    }
};

int main() {
    unordered_set<char> nodes = {'a', 'b', 'c', 'd', 'e', 'f'};
    union_find<char, unordered_set<char>> uf = union_find<char, unordered_set<char>>(nodes);
    string command;
    char arg1;
    char arg2;
    while (true) {
        cout << "find <char>, union <char> <char>, size <char>" << endl;
        cin >> command;
        if (command.compare("find") == 0) {
            cin >> arg1;
            cout << endl << uf.find(arg1);
        } else if (command.compare("union") == 0) {
            cin >> arg1;
            cin >> arg2;
            uf.union_elems(arg1, arg2);
            cout << endl;
        } else if (command.compare("size") == 0) {
            cin >> arg1;
            cout << endl << uf.size(arg1);
        } else {
            return 0;
        }
        cout << endl;
    }
}