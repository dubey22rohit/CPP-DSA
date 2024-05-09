#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector<int> v(5);
    vector<int> v;
    // for (int i = 0; i < v.size(); i++) {
    for (int i = 0; i < 5; i++) {
        // v[i] = i + 1;
        v.push_back(i + 1);
    }
    // Iterator : Pointer to elements within a range of elements, [0,1,2,3,4,5],
    // iterator can point to 0, 1 ,2 etc.
    vector<int>::iterator it;

    // begin gives an iterator pointing to the first element of the vector
    // end points to the next position to the last element of a vector
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}