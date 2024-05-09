#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, int> mp;
    mp["abc"] = 1;
    mp["abc1"] = 2;
    mp["abc2"] = 3;
    mp["abc3"] = 4;
    mp["abc4"] = 5;

    // Every data type has a different kind of an operator, map has different,
    // vector has different etc. This will be a pointer to the first element of
    // the map(A key value Pair);
    unordered_map<string, int>::iterator it = mp.begin();
    while (it != mp.end()) {
        // Since it is an unordered_map, the values will not be in order
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }

    // Find : Returns an iterator
    unordered_map<string, int>::iterator it2 = mp.find("abc");
    mp.erase(it2);  // Delete the key value pair where the iterator is currently
                    // pointing
    mp.erase(it2, it2 + 4);  // Erase, from -> to

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator vit = v.begin();
    while (vit != v.end()) {
        cout << *vit << endl;
        it++;
    }

    return 0;
}