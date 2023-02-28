#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> convertStr(string s) {
    vector<string> ans;
    istringstream f(s);
    string temp;
    while (getline(f, temp, ' ')) {
        ans.push_back(temp);
    }
    return ans;
}

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> mp;
    unordered_map<string, char> mp2;
    vector<string> sarr = convertStr(s);

    int sarrLen = 0;
    for (string element : sarr) sarrLen++;

    if (sarrLen != pattern.length()) {
        return false;
    }

    int i = 0;
    while (i != pattern.length()) {
        if ((mp.find(pattern[i]) != mp.end()) &&
            (mp.at(pattern[i]) != sarr[i])) {
            return false;
        }
        if ((mp2.find(sarr[i]) != mp2.end()) &&
            (mp2.at(sarr[i]) != pattern[i])) {
            return false;
        }
        mp[pattern[i]] = sarr[i];
        mp2[sarr[i]] = pattern[i];
        i++;
    }
    return true;
}

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << "Word pattern? :" << wordPattern(pattern, s);
    return 0;
}