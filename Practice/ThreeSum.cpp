#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {}

int main() {
    int n, target;
    cin >> n;
    vector<int> numbers;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        numbers.push_back(a);
    }

    vector<vector<int>> ans = threeSum(numbers);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}