#include <iostream>

#include "../Helpers/TreeNode.h"
using namespace std;

/**
 * Finds the lowest common ancestor (LCA) of two given nodes in a
 * binary search tree (BST).
 *
 * @param root Pointer to the root node of the BST.
 * @param p Pointer to one of the nodes.
 * @param q Pointer to the other node.
 * @return Pointer to the LCA node.
 *
 * The function traverses the BST by comparing the values of the nodes
 * with the values of the given nodes. If the value of the current node
 * is less than the values of both given nodes, it recursively calls the
 * function on the right subtree. If the value of the current node is
 * greater than the values of both given nodes, it recursively calls the
 * function on the left subtree. If the value of the current node is
 * between the values of the given nodes, it is the LCA and is returned.
 * If the current node is null, indicating that the given nodes are not
 * present in the BST, null is returned.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // If the root node is null, return null
  if (!root) {
    return nullptr;
  }

  // If the value of the root node is less than the values of both given nodes,
  // recursively call the function on the right subtree
  if (root->val < p->val && root->val < q->val) {
    return lowestCommonAncestor(root->right, p, q);
  }

  // If the value of the root node is greater than the values of both given
  // nodes, recursively call the function on the left subtree
  if (root->val > p->val && root->val > q->val) {
    return lowestCommonAncestor(root->left, p, q);
  }

  // If the value of the root node is between the values of the given nodes,
  // it is the LCA and is returned
  return root;
}

int main() {
  TreeNode* root = createTree();
  TreeNode* p = new TreeNode(2);
  TreeNode* q = new TreeNode(8);

  TreeNode* lca = lowestCommonAncestor(root, p, q);
  cout << lca->val;
  return 0;
}