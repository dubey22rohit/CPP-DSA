#include <iostream>
#include <vector>
using namespace std;

class MinStack {
   private:
    vector<int> stkarr;
    vector<int> minVals;

   public:
    MinStack() { minVals.push_back(INT_MAX); }

    void push(int val) {
        stkarr.push_back(val);
        if (minVals.empty()) {
            minVals.push_back(val);
            return;
        }
        if (val <= minVals.back()) {
            if (minVals.back() == INT_MAX) {
                minVals.back() = val;
            } else {
                minVals.push_back(val);
            }
        }
    }

    void pop() {
        if (stkarr.back() == minVals.back()) {
            minVals.pop_back();
        }
        stkarr.pop_back();
    }

    int top() { return stkarr.back(); }

    int getMin() { return minVals.back(); }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    cout << "top: " << obj->top() << "\n";
    obj->pop();
    cout << "getMin: " << obj->getMin() << "\n";
    obj->pop();
    cout << "getMin: " << obj->getMin() << "\n";
    obj->pop();
    obj->push(2147483647);
    cout << "top: " << obj->top() << "\n";
    cout << "getMin: " << obj->getMin() << "\n";
    obj->push(-2147483648);
    cout << "top: " << obj->top() << "\n";
    cout << "getMin: " << obj->getMin() << "\n";
    obj->pop();
    cout << "getMin: " << obj->getMin() << "\n";
    return 0;
}