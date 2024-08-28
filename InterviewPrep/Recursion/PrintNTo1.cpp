#include <iostream>
using namespace std;

void printNos(int N) {
  if (N <= 0) {
    return;
  }
  cout << N << " ";
  printNos(N - 1);
}

int main() {
  printNos(10);
  return 0;
}