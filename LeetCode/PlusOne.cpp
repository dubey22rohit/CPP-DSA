#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    int carry = 0;
    int ld = digits[digits.size() - 1];

    if (ld + 1 <= 9) {
        for (int i = 0; i < digits.size() - 1; i++) {
            ans.push_back(digits[i]);
        }
        ans.push_back(ld + 1);
    } else {
        carry = 1;
    }
    return ans;
}

int main() {
    int n, a;
    cin >> n;
    vector<int> digits;
    for (int i = 0; i < n; i++) {
        cin >> a;
        digits.push_back(a);
    }
    vector<int> ans = plusOne(digits);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}