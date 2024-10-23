#include <iostream>
using namespace std;

// TODO: Need to revisit
class QueueUsingArray {
 private:
  int *nums;
  int front;
  int rear;
  int size;

 public:
  QueueUsingArray() {
    size = 10;
    nums = new int[size];
    front = -1;
    rear = -1;
  }

  void push(int ele) {
    if ((rear + 1) % size == front) {
      cout << "queue full";
      return;
    }
    rear = (rear + 1) % size;
    nums[rear] = ele;
  }

  int pop() {
    if (front == rear) {
      cout << "queue empty";
      return -1;
    }
    int out = nums[front + 1];
    front = (front + 1) % size;
    return out;
  }

  int frontEle() { return nums[front + 1]; }

  int rearEle() { return nums[rear]; }
};

int main() {
  QueueUsingArray *mq = new QueueUsingArray();
  mq->push(10);
  mq->push(11);
  mq->push(12);

  cout << "front: " << mq->frontEle() << endl;
  cout << "rear: " << mq->rearEle() << endl;

  cout << "pop: " << mq->pop() << endl;

  cout << "front: " << mq->frontEle() << endl;
  cout << "rear: " << mq->rearEle() << endl;

  cout << "pop: " << mq->pop() << endl;

  cout << "front: " << mq->frontEle() << endl;
  cout << "rear: " << mq->rearEle() << endl;

  return 0;
}