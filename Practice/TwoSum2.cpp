#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i <= j) {
        if (numbers[i] + numbers[j] == target) {
            return {i + 1, j + 1};
        } else if (numbers[i] + numbers[j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return {};
}

int main() {
    int n, target;
    cin >> n;
    vector<int> numbers;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        numbers.push_back(a);
    }

    cout << "\nenter target:";
    cin >> target;

    vector<int> ans = twoSum(numbers, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}