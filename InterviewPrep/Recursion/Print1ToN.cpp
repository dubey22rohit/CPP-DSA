#include <iostream>
using namespace std;

void printNos(int N) {
  if (N <= 0) {
    return;
  }
  printNos(N - 1);
  cout << N << " ";  // Print after recursuive call will come from 1 - N,
                     // before it would have been N - 1
}
int main() {
  printNos(10);
  return 0;
}