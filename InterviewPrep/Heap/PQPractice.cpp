#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Max heap: as max is on top, i.e first to be popped
  priority_queue<int, vector<int>, less<int>> lessPq;

  // Min heap: as min is on top i.e first to be popped
  priority_queue<int, vector<int>, greater<int>> greaterPq;

  for (int i = 0; i < 10; i++) {
    lessPq.push(i);
    greaterPq.push(i);
  }

  for (int i = 0; i < 10; i++) {
    cout << "\nlessPq: " << lessPq.top();
    lessPq.pop();

    cout << "\ngreaterPq: " << greaterPq.top();
    greaterPq.pop();
  }

  return 0;
}