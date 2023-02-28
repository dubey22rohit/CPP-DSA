#include <iostream>
using namespace std;
#include <stack>

void reverseStack(stack<int> &ip, stack<int> &op) {
    if (ip.size() <= 1) {
        return;
    }
    int last = ip.top();
    ip.pop();
    reverseStack(ip, op);
    while (!ip.empty()) {
        int topel = ip.top();
        ip.pop();
        op.push(topel);
    }
    op.push(last);
    while (!op.empty()) {
        int topel = op.top();
        op.pop();
        ip.push(topel);
    }
}
int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}