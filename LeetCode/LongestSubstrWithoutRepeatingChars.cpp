#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    set<int> visited;
    int max_length = 0;
    int i = 0, j = 0;
    while (j < s.length()) {
        if (visited.find(s[j]) == visited.end()) {
            visited.insert(s[j]);
            j++;
            max_length = max(max_length, j - i);
        } else {
            visited.erase(s[i]);
            i++;
        }
    }
    return max_length;
}

int main() { return 0; }