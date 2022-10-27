#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 2 Types of maps : ordered(made using BST, all operations in O(logn) time)
// unordered_map(made using hash table, all operations in O(1) time)

int main() {
    unordered_map<string, int> mp;

    // insert
    pair<string, int> p("abc", 1);
    mp.insert(p);
    mp["def"] = 2;

    // Find or access
    cout << mp["abc"] << endl;
    cout << mp.at("def") << endl;
    // cout << mp.at("ghi") << endl;Key does not exist : Will throw an error
    // cout << mp["ghi"] << endl;Key does not exist : Will insert default value
    // (0) and return that, not throwing an error.

    // Check presense of a key in map
    // mp.count(key) is the correct way to check if a key is present in the map
    // or not

    // Size
    cout << "size :" << mp.size() << endl;
    mp["ghi"] = 3;
    cout << "size :" << mp.size() << endl;

    if (mp.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    mp.erase("ghi");
    if (mp.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }
    return 0;
}