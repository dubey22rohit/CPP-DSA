#include <iostream>
#include <vector>
using namespace std;

vector<int> ArrayOfProducts(vector<int> &num) {
    vector<int> a;
    int prod = 1;
    for (int i = 0; i < num.size(); ++i) {
        prod *= num[i];
    }
    for (int i = 0; i < num.size(); i++) {
        a.push_back(prod / num[i]);
    }
    return a;
}

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);

    vector<int> ans = ArrayOfProducts(v);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}