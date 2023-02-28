#include<iostream>
using namespace std;
#include<vector>
int main() {
    vector<int> v;
    for (int i = 0; i < v.size(); i++)
    {
        v.push_back(i * 5);
    }
    vector<int>::iterator it;
    for (it = v.begin();it != v.end();it++) {
        cout << *it << " ";
    }

}