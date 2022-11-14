#include <iostream>
#include <vector>
using namespace std;

// An inversion in an array is when i < j and A[i] > A[j]
int inversionCount(vector<int> &nums) {
    int c = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = 0; j < nums.size(); j++) {
            if (nums[i] > nums[j] && i < j) {
                c++;
            }
        }
    }
    return c;
}

int main() {
    vector<int> nums(5);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);

    cout << "Inversion count: " << inversionCount(nums) << endl;

    return 0;
}