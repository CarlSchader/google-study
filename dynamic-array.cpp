#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class DynamicArray {
    private:
        T *array;
        int length; // num of elems stored
        int size; // size of internal array
    public:
        DynamicArray() {
            size = 2;
            length = 0;
            array = new T[size];
        }

        T get(int i) {
            if (i < length) {
                return array[i];
            } else {
                throw range_error("index out of range"); 
            }
        }

        void set(int i, T x) {
            if (i < length) {
                array[i] = x;
            } else {
                throw range_error("index out of range"); 
            }
        }

        void insert(T x) {
            if (length == size) {
                size *= 2;
                T *newArray = new T[size];
                for (int i = 0; i < length; i++) {
                    newArray[i] = array[i];
                }
                delete array;
                array = newArray;
            }
            array[length] = x;
            length++;
        }

        void remove(int i) {
            if (i < length) {
                for (int j = i; j < length - 1; j++) {
                    array[j] = array[j + 1];
                }
                length--;
            } else {
                throw range_error("index out of range"); 
            }
        }

        int getLength() {
            return length;
        }
};

template<typename T>
void printArray(DynamicArray<T>& dArray) {
    for (int i = 0; i < dArray.getLength(); i++) {
        cout << dArray.get(i) << endl;
    }
}

int main() {
    DynamicArray<int> dArray = DynamicArray<int>();
    string command;
    int val = 0;
    while (true) {
        cout << "insert <num>, remove <index>" << endl;
        cin >> command;
        cin >> val;
        if (command.compare("insert") == 0) {
            dArray.insert(val);
        } else if (command.compare("remove") == 0) {
            dArray.remove(val);
        } else {
            return 0;
        }
        cout << endl << "array" << endl;
        printArray(dArray);
    }
}
