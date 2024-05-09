#include <iostream>

#include "TreeNode.h"
using namespace std;

TreeNode* BSTFromSortedArray(int s, int e, vector<int>& nums) {
    if (s > e) {
        return NULL;
    }

    int mid = s + (e - s) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->lchild = BSTFromSortedArray(s, mid - 1, nums);
    root->rchild = BSTFromSortedArray(mid + 1, e, nums);

    return root;
}

TreeNode* BSTFromSortedArray(vector<int>& nums) {
    return BSTFromSortedArray(0, nums.size() - 1, nums);
}

int main() {
    int n;

    cin >> n;
    vector<int> nums;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    TreeNode* root = BSTFromSortedArray(nums);
    printTree(root);

    return 0;
}