/*
Solution to the problem found at https://open.kattis.com/problems/substrings
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct suffixAndIndex {
    string suffix;
    int index;
};

int cmp(suffixAndIndex a, suffixAndIndex b) {
    return a.suffix < b.suffix;
}

int *suffix_array(char *line, int length) { // n^2
    int length = line.length();
    suffixAndIndex array[length];
    for (int i = 0; i < length; i++) {
        suffixAndIndex sai = {line.substr(i, length - i), i};
        array[i] = sai;
    }
    sort(array, array + length, cmp);
    int *sa = new int[length];
    for (int i = 0; i < length; i++) {
        sa[i] = array[i].index;
    }
    return sa;
}

int *lcp(string& line, int sa[], int size) {
    int *array = new int[size];
    array[0] = 0;
    for (int i = 1; i < size; i++) {
        
    }
}

int uniqueRepeatedSubstringCount(string& line) {
    return 1;
}

template<typename T>
void printArray(T array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main() {
    string lineString;
    getline(cin, lineString);
    int cases = stoi(lineString);
    for (int i = 0; i < cases; i++) {
        getline(cin, lineString);
        int *sa = suffix_array(lineString);
        cout << lineString << endl;
        printArray<int>(sa, lineString.length());
        // cout << uniqueRepeatedSubstringCount(lineString) << endl;
    }
}
