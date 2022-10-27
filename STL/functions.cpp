#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    // Sort
    int arr[] = {1, 3, 2, 5, 7, 6};
    // sort(arr, arr + 6);//Sort in increasing order
    sort(arr, arr + 6, greater<int>());  // Sort in decreasing order
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}