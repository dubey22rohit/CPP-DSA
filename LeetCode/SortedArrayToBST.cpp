#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"
using namespace std;

TreeNode* sortedArrayToBST(int s, int e, vector<int>& nums) {
    if (s > e) {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(s, mid - 1, nums);
    root->right = sortedArrayToBST(mid + 1, e, nums);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(0, nums.size() - 1, nums);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    TreeNode* root = sortedArrayToBST(nums);
    printTree(root);

    return 0;
}