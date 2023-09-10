#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParenthesis(int n) {}

int main() {
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for (auto c : ans) {
        cout << c << " ";
    }
    return 0;
}