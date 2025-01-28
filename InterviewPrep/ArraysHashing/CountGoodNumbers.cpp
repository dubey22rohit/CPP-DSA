#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// TODO: Finish
int countGoodNumbers(long long n) {
  unordered_map<int, int> hm;
  unordered_set<int> primeNos = {2, 3, 5, 7};
  int idx = 0;
  while (n != 0) {
    int rem = n % 10;
    hm[idx] = rem;
    n /= 10;
    idx++;
  }

  int len = hm.size();
  int gn = 0;

  for (int i = 0; i < hm.size(); i++) {
    if (primeNos.count(len - 1 - i) && primeNos.count(hm[len - 1 - i])) {
      gn++;
    } else if ((len - 1 - i) % 2 == 0 && hm[len - 1 - i] % 2 == 0) {
      gn++;
    }
  }

  return gn;
}

int main() {
  cout << countGoodNumbers(1);
  return 0;
}