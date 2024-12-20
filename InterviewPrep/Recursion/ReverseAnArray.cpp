#include <iostream>
#include <vector>
using namespace std;

void reverseArrayRecursive2(vector<int>& arr, int si) {
  if (si >= arr.size() / 2) {
    return;
  }
  swap(arr[si], arr[arr.size() - si - 1]);
  reverseArrayRecursive2(arr, si + 1);
}
void reverseArrayRecursive(vector<int>& arr, int si, int ei) {
  if (si > ei) {
    return;
  }
  int temp = arr[si];
  arr[si] = arr[ei];
  arr[ei] = temp;
  reverseArrayRecursive(arr, si + 1, ei - 1);
}

void reverseArray(vector<int>& arr, int n) {
  int i = 0, j = n - 1;
  while (i < j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
}

int main() {
  vector<int> arr{1, 2, 3, 4, 5};
  vector<int> arr2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> arr3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  reverseArray(arr, arr.size());
  for (auto a : arr) {
    cout << a << " ";
  }

  cout << endl;

  reverseArrayRecursive(arr2, 0, arr2.size() - 1);
  for (auto a : arr2) {
    cout << a << " ";
  }

  cout << endl;

  reverseArrayRecursive2(arr3, 0);
  for (auto a : arr3) {
    cout << a << " ";
  }

  return 0;
}