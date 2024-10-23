#include <iostream>
using namespace std;

class StackUsingArray {
 private:
  int *nums;
  int size;
  int top;

 public:
  StackUsingArray() {
    top = -1;
    size = 100;
    nums = new int[size];
  }

  void push(int ele) {
    top++;
    nums[top] = ele;
  }
  int pop() {
    if (top == -1) {
      return -1;
    }
    int ele = nums[top];
    top--;
    return ele;
  }

  int sizeOfSt() { return top + 1; }

  int topEle() { return nums[top]; }
};

int main() {
  StackUsingArray *st = new StackUsingArray();
  st->push(10);
  st->push(11);
  st->push(12);

  cout << "size:" << st->sizeOfSt() << endl;

  cout << "top:" << st->topEle() << endl;
  cout << "pop:" << st->pop() << endl;
  cout << "top:" << st->topEle() << endl;
  cout << "pop:" << st->pop() << endl;

  cout << "size:" << st->sizeOfSt() << endl;

  return 0;
}