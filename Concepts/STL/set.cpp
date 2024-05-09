#include <iostream>
#include <set>
using namespace std;

int main() {
    // A set has all unique keys
    // Implemented using a balanced binary search tree
    set<int> s;
    int arr[] = {1, 2, 3, 4, 5, 6, 5};
    for (int i = 0; i < 7; i++) {
        s.insert(arr[i]);
    }

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Finding an element
    // Find returns an iterator, and it keeps going towards end to find the
    // specified element.
    // find take O(logn) time : same time to search in a balanced BST
    if (s.find(6) == s.end()) {
        cout << "element not found";
    } else {
        cout << "element found";
    }

    return 0;
}