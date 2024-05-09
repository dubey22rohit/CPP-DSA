#include <iostream>
#include <vector>
using namespace std;

// TC: O(N)
// SC: O(1)
void shiftAndUpdate(vector<int>& threeLargest, int num, int idx) {
    for (int i = 0; i <= idx; i++) {
        if (i == idx) {
            threeLargest[i] = num;
        } else {
            threeLargest[i] = threeLargest[i + 1];
        }
    }
}

void updateLargest(vector<int>& threeLargest, int num) {
    if (threeLargest[2] == -100 || threeLargest[2] < num) {
        shiftAndUpdate(threeLargest, num, 2);
    } else if (threeLargest[1] == -100 || threeLargest[1] < num) {
        shiftAndUpdate(threeLargest, num, 1);
    } else if (threeLargest[0] == -100 || threeLargest[0] < num) {
        shiftAndUpdate(threeLargest, num, 0);
    }
}

vector<int> threeLargestNums(vector<int>& nums) {
    vector<int> threeLargest{-100, -100, -100};
    for (auto num : nums) {
        updateLargest(threeLargest, num);
    }
    return threeLargest;
}

int main() {
    int n;
    cin >> n;
    vector<int> ip;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        ip.push_back(a);
    }

    vector<int> ans = threeLargestNums(ip);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}