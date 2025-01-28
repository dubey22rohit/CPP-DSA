#include <iostream>
using namespace std;

// https://leetcode.com/problems/rotate-string/
bool rotateString(string s, string goal) {
  if (s.size() != goal.size()) {
    return false;
  }
  s += s;
  if (s.find(goal) != string::npos) {
    return true;
  }
  return false;
}

int main() { return 0; }