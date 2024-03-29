#include <vector>
using namespace std;
int carFleet(int target, vector<int> &position, vector<int> &speed) {
  int n = position.size();
  vector<pair<int, double>> cars;
  for (int i = 0; i < n; i++) {
    double time = (double)(target - position[i]) / speed[i];
    cars.push_back({position[i], time});
  }

  sort(cars.begin(), cars.end());

  double maxTime = 0.0;
  int result;

  for (int i = n - 1; i >= 0; --i) {
    double time = cars[i].second;
    if (time > maxTime) {
      maxTime = time;
      result++;
    }
  }
  // 3164212
  // vault8.com
  // 1235789
  // 6778654
  // .-........
  return result;
}
