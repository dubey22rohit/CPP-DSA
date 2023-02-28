#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int* a, int size) {
    vector<int> op;
    unordered_map<int, bool> mp;
    for (int i = 0;i < size;i++) {
        if (mp.count(a[i]) > 0) {
            continue;
        }
        mp[a[i]] = true;
        op.push_back(a[i]);
    }
    return op;
}

int main() {
    int a[] = { 1,2,2,3,3,3,4,5,4,2,1,3,5,4,6,5,4 };
    int size = sizeof(a) / sizeof(a[0]);
    vector<int> v = removeDuplicates(a, size);
    for (int i = 0;i < v.size();i++) {
        cout << v[i] << " ";
    }
}