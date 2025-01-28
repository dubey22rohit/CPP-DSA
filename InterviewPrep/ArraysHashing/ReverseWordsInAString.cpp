#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/

// Space: O(n)
// Time: O(n)
string reverseWords(string s) {
  vector<string> words;
  int i = 0;
  while (i < s.size()) {
    if (s[i] != ' ') {
      string currStr;
      while (s[i] != ' ' && i < s.size()) {
        currStr.push_back(s[i]);
        i++;
      }
      words.push_back(currStr);
    }
    i++;
  }

  string result = "";

  for (int k = words.size() - 1; k >= 0; k--) {
    if (k == 0) {
      result.append(words[k]);
    } else {
      result.append(words[k].append(" "));
    }
  }

  return result;
}

// Space: O(1)
// Time: O(n)
string reverseWordsOp(string s) {
  int i = 0;
  string ans = "";
  string temp = "";
  while (i < s.size()) {
    if (s[i] != ' ') {
      temp += s[i];
    } else if (s[i] == ' ' && temp != "") {
      if (ans == "") {
        ans = temp;
      } else {
        ans = temp + " " + ans;
      }
      temp = "";
    }
    i++;
  }

  if (temp != "") {
    if (ans == "") {
      ans = temp;
    } else {
      ans = temp + " " + ans;
    }
  }
  return ans;
}

int main() {
  cout << reverseWords("the sky is blue");
  cout << num;
  return 0;
}