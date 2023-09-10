#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool checkOperation(string s) {
    if (s == "+" || s == "-" || s == "/" || s == "*") {
        return true;
    }
    return false;
}

int getOperationAns(int o1, int o2, string op) {
    if (op == "+") {
        return o1 + o2;
    }
    if (op == "-") {
        return o1 - o2;
    }
    if (op == "*") {
        return o1 * o2;
    }
    if (op == "/") {
        return o1 / o2;
    }
    return -1;
}

int evalRPN(vector<string>& tokens) {
    stack<string> stk;
    for (auto s : tokens) {
        if (!checkOperation(s)) {
            stk.push(s);
        } else {
            int o1 = stoi(stk.top());
            stk.pop();
            int o2 = stoi(stk.top());
            stk.pop();
            int ans = getOperationAns(o2, o1, s);
            stk.push(to_string(ans));
        }
    }
    return stoi(stk.top());
}

int main() {
    int n;
    cin >> n;

    vector<string> tokens(n);

    string s;
    while (n--) {
        getline(cin, s);
        tokens.push_back(s);
    }

    int rpn = evalRPN(tokens);
    cout << rpn;

    return 0;
}