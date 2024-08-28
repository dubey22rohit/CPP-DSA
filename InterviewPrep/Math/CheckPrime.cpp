#include <iostream>
using namespace std;

bool checkPrime(int N) {
  if (N > 0 && N <= 2) {
    return true;
  }
  for (int i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  cout << checkPrime(1) << endl;
  cout << checkPrime(2) << endl;
  cout << checkPrime(7) << endl;
  cout << checkPrime(12) << endl;
  cout << checkPrime(11) << endl;
  return 0;
}