#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main() {
    unordered_map<string, int> mp;
    mp["abc1"] = 1;
    mp["abc2"] = 2;
    mp["abc3"] = 3;
    mp["abc4"] = 4;
    mp["abc5"] = 5;
    mp["abc6"] = 6;

    unordered_map<string, int>::iterator it = mp.begin();
    while (it != mp.end()) {
        cout << "Key : " << it->first << " " << "Value : " << it->second << endl;
        it++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator vi = v.begin();
    while(vi != v.end()){
        cout << *vi << endl;
        vi++;
    }
}