#include <iostream>
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-bst/

TreeNode* getSuccessor(TreeNode* curr) {
  curr = curr->right;
  while (curr && curr->left) {
    curr = curr->left;
  }
  return curr;
}
TreeNode* deleteNode(TreeNode* root, int key) {
  if (!root) {
    return NULL;
  }
  if (key > root->val) {
    root->right = deleteNode(root->right, key);
  } else if (key < root->val) {
    root->left = deleteNode(root->left, key);
  } else {
    if (!root->left) {
      TreeNode* temp = root->right;
      delete root;
      return temp;
    }

    if (!root->right) {
      TreeNode* temp = root->left;
      delete root;
      return temp;
    }

    // Deleting a node with both children is not so simple. Here we have to
    // delete the node is such a way, that the resulting tree follows the
    // properties of a BST.

    // The trick is to find the inorder successor of the node.
    // Copy contents of the inorder successor to the node,
    // and delete the inorder successor.

    TreeNode* succ = getSuccessor(root);
    root->val = succ->val;
    root->right = deleteNode(root->right, succ->val);
  }

  return root;
}

int main() { return 0; }