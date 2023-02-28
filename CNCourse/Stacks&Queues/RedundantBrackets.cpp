#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool checkRedundant(string str) {
    stack<int> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ')') {
            s.push(str[i]);
        } else {
            int c = 0;
            while (!s.empty()) {
                int top = s.top();
                if (top != '(') {
                    s.pop();
                    c++;
                }
            }
        }
    }
}

int main() {}