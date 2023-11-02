#include <iostream>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h) {}

int main() {
  int n;
  cin >> n;

  vector<int> piles(n);

  int a;
  while (n--) {
    cin >> a;
    piles.push_back(a);
  }

  int h;
  cin >> h;

  int minSpeed = minEatingSpeed(piles, h);
  cout << "\n" << minSpeed;
  return 0;
}
