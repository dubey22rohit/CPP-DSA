#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
  vector<int> ans(digits.size());
  int carry = 0;
  for (int i = digits.size() - 1; i >= 0; --i) {
    int sum;
    if (i == digits.size() - 1) {
      sum = digits[i] + 1 + carry;
    } else {
      sum = digits[i] + carry;
    }
    if (sum > 9) {
      ans[i] = sum % 10;
      carry = sum / 10;
    } else {
      ans[i] = sum;
      carry = 0;
    }
  }

  if (carry != 0) {
    ans.insert(ans.begin(), carry);
  }

  return ans;
}

int main() {
  vector<int> digits{1, 2, 4};
  vector<int> ans = plusOne(digits);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "";
  }
  return 0;
}
