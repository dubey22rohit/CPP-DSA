#include <iostream>
#include <queue>
using namespace std;

// TODO: Revisit
class MedianFinder {
 public:
  // Max Heap
  priority_queue<double, vector<double>, less<double>> greaterHalf;
  // Min Heap
  priority_queue<double, vector<double>, greater<double>> lesserHalf;
  MedianFinder() {}

  void addNum(int num) {
    if (this->lesserHalf.empty()) {
      this->lesserHalf.push(num);
    } else {
      if (this->lesserHalf.top() < num) {
        this->greaterHalf.push(num);
      } else {
        this->lesserHalf.push(num);
      }
    }
  }

  double findMedian() {
    if ((this->greaterHalf.size() + this->lesserHalf.size()) % 2) {
      if (this->greaterHalf.size() > this->lesserHalf.size())
        return this->greaterHalf.top();
      else
        return this->lesserHalf.top();
    }
    return (this->greaterHalf.top() + this->lesserHalf.top()) / 2;
  }
};

int main() { return 0; }
