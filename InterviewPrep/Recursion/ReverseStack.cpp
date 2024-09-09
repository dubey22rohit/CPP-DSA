#include <iostream>
#include <stack>
using namespace std;

void addToBottom(stack<int> &St, int el) {
  if (St.size() == 0) {
    St.push(el);
  } else {
    int a = St.top();
    St.pop();
    addToBottom(St, el);
    St.push(a);
  }
}

void Reverse(stack<int> &St) {
  if (St.empty()) {
    return;
  }
  int top = St.top();
  St.pop();
  Reverse(St);
  addToBottom(St, top);
}

int main() {
  stack<int> s;
  s.push(7);
  s.push(5);
  s.push(4);
  Reverse(s);
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  return 0;
}
