#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
 private:
  // Min priority queue, smallest element is removed first.
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (int n : nums) {
      pq.push(n);
    }
  }

  int add(int val) {
    this->pq.push(val);
    while (pq.size() > this->k) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  vector<int> nums{4, 5, 8, 2};
  KthLargest* obj = new KthLargest(3, nums);
  int param_1 = obj->add(3);
  cout << param_1 << endl;
  int param_2 = obj->add(5);
  cout << param_2 << endl;
  int param_3 = obj->add(10);
  cout << param_3 << endl;
  int param_4 = obj->add(9);
  cout << param_4 << endl;
  int param_5 = obj->add(4);
  cout << param_5 << endl;
  return 0;
}