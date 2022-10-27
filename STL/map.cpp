#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
    // Map created using balanced BST, o(logn) for find, insert, delete
    // unordered_map is created using HashTable and it takes o(1) time to find,
    // insert and delete,worst case o(n)
    int arr[] = {1, 2, 3, 4, 5, 6, 5, 6, 4};
    map<int, int> m;
    for (int i = 0; i < 9; i++) {
        m[arr[i]]++;
    }

    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << "key : " << it->first << " value:" << it->second << endl;
    }
    cout << endl;
    m.erase(1);
    for (it = m.begin(); it != m.end(); it++) {
        cout << "key : " << it->first << " value:" << it->second << endl;
    }

    return 0;
}