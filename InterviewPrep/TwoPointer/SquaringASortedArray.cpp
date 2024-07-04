#include <iostream>
#include <vector>
using namespace std;

static vector<int> makeSquares(const vector<int> &arr) {
  int n = arr.size();
  vector<int> squares(n);
  int highestSquareIdx = n - 1;
  int left = 0, right = n - 1;
  while (left <= right) {
    int leftsq = arr[left] * arr[left];
    int rightsq = arr[right] * arr[right];
    if (leftsq > rightsq) {
      squares[highestSquareIdx--] = leftsq;
      left++;
    } else {
      squares[highestSquareIdx--] = rightsq;
      right--;
    }
  }

  return squares;
}

int main() {
  const vector<int> arr{-2, -1, 0, 2, 3};
  const vector<int> ans = makeSquares(arr);
  for (const int a : ans) {
    cout << a << " ";
  }
  return 0;
}