#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int ix = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] != nums[i]) {
            nums[ix] = nums[i];
            ix++;
        }
    }
    return ix;
}

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    cout << "Original length : " << a.size() << endl;
    cout << "After removing duplicates length : " << removeDuplicates(a)
         << endl;
    return 0;
}