#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
  // max heap
  priority_queue<int> lower;

  // min heap
  priority_queue<int, vector<int>, greater<int>> higher;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (lower.empty()) {
      lower.push(num);
      return;
    }
    if (lower.size() > higher.size()) {
      if (lower.top() > num) {
        higher.push(lower.top());
        lower.pop();
        lower.push(num);
      } else {
        higher.push(num);
      }
    } else {
      if (num > higher.top()) {
        lower.push(higher.top());
        higher.pop();
        higher.push(num);
      } else {
        lower.push(num);
      }
    }
  }
  double findMedian() {
    if (lower.size() == higher.size()) {
      return lower.top() + (higher.top() - lower.top()) / 2.0;
    } else {
      if (lower.size() > higher.size()) {
        return lower.top();
      } else {
        return higher.top();
      }
    }
  }
};

int main() {}
