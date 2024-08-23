#include <iostream>
#include <vector>
using namespace std;

/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
 * together with the x-axis forms a container, such that the total area of
 * water it can contain is maximized.
 *
 * @param height A vector of non-negative integers, where each represents a
 * point at coordinate (i, ai).
 * @return The maximum area of water that can be contained in the container.
 */
int maxArea(vector<int>& height) {
  // Disable the buffering of cout
  // For performance optimization, does not impact the core logic.
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  // Initialize the left and right pointers
  int left = 0, right = height.size() - 1;
  int maxArea = INT_MIN;

  // Iterate through the vector and calculate the maximum area
  while (left < right) {
    int lh = height[left];
    int rh = height[right];

    // Calculate the current area
    int currArea = min(lh, rh) * (right - left);

    // Update the maximum area
    maxArea = max(maxArea, currArea);

    // Move the pointers
    if (lh < rh) {
      left++;
    } else {
      right--;
    }
  }

  // Return the maximum area
  return maxArea;
}

int main() {
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << maxArea(height);
  return 0;
}