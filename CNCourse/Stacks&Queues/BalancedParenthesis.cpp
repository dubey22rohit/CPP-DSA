#include <iostream>
#include <stack>
#include <string>
using namespace std;

// bool checkPairs(char a, char b) {
//     if (a == '{' && b == '}') {
//         return true;
//     } else if (a == '(' && b == ')') {
//         return true;
//     } else if (a == '[' && b == ']') {
//         return true;
//     }
//     return false;
// }

bool isBalanced(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (s.empty()) {
                return false;
            }
            char topChar = s.top();
            s.pop();
            if (str[i] == ')' && topChar == '(') {
                continue;
            } else {
                return false;
            }
        }
    }
    return s.empty();
}
bool isBalancedTwo(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (s.empty()) {
                return false;
            }
            char topCh = s.top();
            s.pop();
            if (str[i] == ')' && topCh == '(') {
                continue;
            } else if (str[i] == '}' && topCh == '{') {
                continue;
            } else if (str[i] == ']' && topCh == '[') {
                continue;
            } else {
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    string str;
    cin >> str;
    cout << isBalanced(str);
}