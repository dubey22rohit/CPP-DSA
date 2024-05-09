#include <iostream>
#include <vector>
using namespace std;

// TODO:Write an optimized solution for this
vector<int> replaceElements(vector<int> &arr) {
    if (arr.size() == 1) {
        arr[0] = -1;
        return arr;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (i == arr.size() - 1) {
            arr[i] = -1;
            break;
        }
        int maxToRight = INT32_MIN;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] > maxToRight) {
                maxToRight = arr[j];
            }
        }
        arr[i] = maxToRight;
    }
    return arr;
}

int main() {
    vector<int> arr;
    arr.push_back(17);
    arr.push_back(18);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(1);

    vector<int> ans = replaceElements(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}