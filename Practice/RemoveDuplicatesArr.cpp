#include <iostream>
using namespace std;

// [1, 1, 2, 3, 4, 5, 5, 6];
int remove(vector<int> arr) {
  int nextNonduplicate = 1;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[nextNonduplicate - 1] != arr[i]) {
      arr[nextNonduplicate] = arr[i];
      nextNonduplicate++;
    }
  }
  return nextNonduplicate;
}

int remove2(vector<int> arr) {
  int i = 0, j = 1, count = 0;
  while (j < arr.size()) {
    if (arr[i] != arr[j]) {
      count++;
    }
    i++;
    j++;
  }
  return ++count;
}

int main() {
  vector<int> arr{1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
  int ans = remove(arr);
  int ans2 = remove2(arr);
  cout << ans << endl;
  cout << ans2;
  return 0;
}
