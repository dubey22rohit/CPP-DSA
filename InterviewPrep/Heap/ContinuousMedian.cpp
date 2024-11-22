#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
 private:
  // Max heap
  priority_queue<int> lower;

  // Min heap
  priority_queue<int, vector<int>, greater<int>> higher;

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (lower.empty()) {
      lower.push(num);
      return;
    }

    if (lower.size() > higher.size()) {
      if (num < lower.top()) {
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
    }
    if (lower.size() > higher.size()) {
      return lower.top();
    } else {
      return higher.top();
    }
  }
};

int main() { return 0; }
