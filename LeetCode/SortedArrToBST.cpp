#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    TreeNode* root = new TreeNode(mid);
    while (s < e) {
    }
}

int main() { return 0; }