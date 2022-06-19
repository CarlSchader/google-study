#include <iostream>
#include <stdexcept>

using namespace std;

class fenwick_tree {
    private:
    int size;
    int array[];

    int lsb(int i) {
        int val = 1;
        while (i % 2 == 0) {
            i >>= 1;
            val <<= 1;
        }
        return val;
    }

    int prefix(int i) {
        int sum = 0;
        while (i > 0) {
            sum += array[i - 1];
            i -= lsb(i);
        }
        return sum;
    }
    
    public:
    fenwick_tree(int val_array[], int array_size) {
        size = array_size;
        for (int i = 0; i < size; i++) {
            array[i] = val_array[i];
        }
        for (int i = 1; i <= size; i++) {
            int index = i - 1;
            int parent = i + lsb(i) - 1;
            if (parent < size) {
                array[parent] += array[index];
            }
        }
    }

    int range(int i, int j) {
        if (i >= 0 && i < size && j >= 0 && j <= size) {
            return prefix(j) - prefix(i);
        } else {
            throw invalid_argument("indices out of bounds");
        }
    }

    void point_update(int i, int x) {
        int dif = x - array[i];
        array[i] = x;
        i += lsb(i + 1);
        while (i < size) {
            array[i] += dif;
            i += lsb(i + 1);
        }
    }
};

int main() {
    int input_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fenwick_tree tree = fenwick_tree(input_array, 10);
    string command;
    int arg1;
    int arg2;
    while (true) {
        cout << "range <index> <index>, update <index> <int>" << endl;
        cin >> command;
        if (command.compare("range") == 0) {
            cin >> arg1;
            cin >> arg2;
            cout << tree.range(arg1, arg2) << endl;
        } else if (command.compare("update") == 0) {
            cin >> arg1;
            cin >> arg2;
            tree.point_update(arg1, arg2);
        } else {
            return 0;
        }
        cout << endl;
    }
    return 0;
}
