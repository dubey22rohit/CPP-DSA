#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Incomplete
string exceptionString(int n) {
    if (exceptions.find(n) != exceptions.end()) {
        return exceptions[n];
    } else {
        return "";
    }
}
string intToRoman(int num) {
    unordered_map<int, string> hm;
    hm[1] = "I";
    hm[5] = "V";
    hm[10] = "X";
    hm[50] = "L";
    hm[100] = "C";
    hm[500] = "D";
    hm[1000] = "M";
    hm[4] = "IV";
    hm[9] = "IX";
    hm[40] = "XL";
    hm[90] = "XC";
    hm[400] = "CD";
    hm[900] = "CM";

    string ans = "";

    while (num > 0) {
        int rem = num % 10;
        string ex = exceptionString(rem);
        if (ex != "") {
            ans += ex;
        } else {
            ans += rem;
        }
        num /= 10;
    }
    return ans;
}

int main() {
    int ip;
    cin >> ip;
    string ans = intToRoman(ip);
    cout << ans;
    return 0;
}