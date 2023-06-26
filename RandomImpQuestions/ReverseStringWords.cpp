#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string S) {
    vector<string> helper;
    stringstream ss(S);
    string word;
    while (!ss.eof()) {
        getline(ss, word, '.');
        helper.push_back(word);
    }
    string ans = "";
    for (int i = helper.size() - 1; i >= 0; i--) {
        if (i == 0) {
            ans += helper[i];
            break;
        }
        ans += helper[i] + '.';
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << reverseWords(s) << endl;

    return 0;
}