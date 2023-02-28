#include<iostream>
#include<unordered_map>
using namespace std;

int maxFreqElem(int* arr, int n) {
    unordered_map<int, int> mp;
    int maxFreq;
    for (int i = 0;i < n;i++) {
        ++mp[arr[i]];
        maxFreq = max(maxFreq, mp[arr[i]]);
    }
    int ans;
    for (int i = 0; i < n; i++) {
        if (mp[arr[i]] == maxFreq) {
            return arr[i];
            break;
        }
    }
    return ans;
}

int main() {
    int arr[] = { 1,2,2,2,2,3,4,4,2,2,5,6,7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxFreqElem(arr, n);
}