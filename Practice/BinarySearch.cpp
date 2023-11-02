#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int x) {
  int s = 0, e = n - 1;
  int mid;
  while (s <= e) {
    mid = s + (e - s) / 2;
    if (input[mid] > x) {
      e = mid - 1;
    } else if (input[mid] < x) {
      s = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  int *input = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }

  int x;
  cin >> x;
  int ans = binarySearch(input, n, x);
  printf("%d found at index: %d", x, ans);

  return 0;
}
