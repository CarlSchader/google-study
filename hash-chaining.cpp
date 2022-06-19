#include <iostream>
#include <stdexcept>
#include <forward_list>
#include <tuple>

using namespace std;

template<typename keyType, typename valType>
struct entry {
    keyType key;
    valType val;
};

template<typename keyType, typename valType> 
class hash_table {
    private:
    int size;
    forward_list<entry<keyType, valType> > *table;
    int (*hash)(keyType);

    public:
    hash_table(int (*hash_function)(keyType), int table_size) {
        size = table_size;
        table = new forward_list<entry<keyType, valType> >[size];
        hash = hash_function;
    }

    void set(keyType key, valType val) {
        forward_list<entry<keyType, valType> > *list = &table[hash(key)];
        cout << hash(key) << endl;
        for (entry<keyType, valType>& kvpair : *list) {
            if (kvpair.key == key) {
                kvpair.val = val;
                return;
            }
        }
        entry<keyType, valType> newEntry = {key, val};
        list->push_front(newEntry);
        cout << list->front().key << " " << list->front().val << endl;
    }

    valType get(keyType key) {
        forward_list<entry<keyType, valType> > *list = &table[hash(key)];
        cout << hash(key) << endl;
        for (entry<keyType, valType>& kvpair : *list) {
            cout << kvpair.key << " " << kvpair.val << endl;
            if (kvpair.key == key) {
                return kvpair.val;
            }
        }
        throw invalid_argument("key not found");
    }
};

int hash_func(char x) {
    return (int)x % 10;
}

int main() {
    hash_table<char, char> dict = hash_table<char, char>(hash_func, 10);
    string command;
    char arg1;
    char arg2;
    while (true) {
        cout << "set <char> <char>, get <char>" << endl;
        cin >> command;
        if (command.compare("set") == 0) {
            cin >> arg1;
            cin >> arg2;
            dict.set(arg1, arg2);
        } else if (command.compare("get") == 0) {
            cin >> arg1;
            cout << endl << dict.get(arg1);
            cout << endl;
        } else {
            return 0;
        }
        cout << endl;
    }
}