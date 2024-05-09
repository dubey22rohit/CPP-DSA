#include <iostream>
#include <string>
using namespace std;

// For a string of length n we can have 2^n substrings
int subsequences(string ip, string op[]) {
    if (ip.empty()) {
        op[0] = "";
        return 1;
    }
    string smallStr = ip.substr(1);
    int smallOp = subsequences(smallStr, op);
    for (int i = 0; i < smallOp; i++) {
        op[i + smallOp] = ip[0] + op[i];
    }
    return 2 * smallOp;
}

int main() {
    string ip;
    getline(cin, ip);
    string *op = new string[1000];
    int count = subsequences(ip, op);
    for (int i = 0; i < count; i++) {
        cout << op[i] << endl;
    }
    return 0;
}