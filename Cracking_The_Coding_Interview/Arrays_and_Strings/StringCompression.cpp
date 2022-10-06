#include <iostream>
#include <string>
using namespace std;

string CompressString(string str) {
    size_t ol = str.length();
    if (ol < 2) {
        return str;
    }
    string out;
    int count = 1;
    for (size_t i = 1; i < ol; i++) {
        if (str[i - 1] == str[i]) {
            ++count;
        } else {
            out += str[i - 1];
            out += to_string(count);
            count = 1;
        }
        if (out.length() >= ol) {
            return str;
        }
    }
    out += str[ol - 1];
    out += to_string(count);
    return out;
}

int main() {
    string str, out;
    cout << "Enter a string : ";
    cin >> str;
    out = CompressString(str);
    cout << endl;
    cout << out;
    return 0;
}