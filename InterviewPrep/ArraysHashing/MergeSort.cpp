#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e) {
  vector<int> temp;
  int m = s + (e - s) / 2;
  int i = s, j = m + 1;
  while (i <= m && j <= e) {
    if (arr[i] < arr[j]) {
      temp.push_back(arr[i]);
      i++;
    } else {
      temp.push_back(arr[j]);
      j++;
    }
  }
  while (i <= m) {
    temp.push_back(arr[i]);
    i++;
  }
  while (j <= e) {
    temp.push_back(arr[j]);
    j++;
  }

  cout << "\n";
  for (auto t : temp) {
    cout << t << " ";
  }
  cout << "\n";

  for (int z = s; z <= e; ++z) {
    arr[z] = temp[z - s];
  }
}

void mergeSort(vector<int> &arr, int s, int e) {
  if (s >= e) {
    return;
  }

  int mid = s + (e - s) / 2;
  mergeSort(arr, s, mid);
  mergeSort(arr, mid + 1, e);
  merge(arr, s, e);
}

int main() {
  vector<int> arr{5, 1, 2, 7, 3, 6, 9, 8};
  mergeSort(arr, 0, arr.size() - 1);
  for (int a : arr) {
    cout << a << " ";
  }
  return 0;
}