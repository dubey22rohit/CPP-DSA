#include <iostream>
#include <queue>
using namespace std;
class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() {
    this->val = 0;
    this->left = nullptr;
    this->right = nullptr;
  }

  TreeNode(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};

TreeNode *createTree() {
  int data;
  cout << "Enter root data: ";
  cin >> data;
  TreeNode *root = new TreeNode(data);
  queue<TreeNode *> pn;
  pn.emplace(root);
  while (!pn.empty()) {
    TreeNode *currNode = pn.front();
    pn.pop();

    printf("Enter data for left child of %d: ", currNode->val);
    cin >> data;
    if (data != -1) {
      TreeNode *leftChild = new TreeNode(data);
      currNode->left = leftChild;
      pn.emplace(leftChild);
    }

    printf("Enter data for right child of %d: ", currNode->val);
    cin >> data;
    if (data != -1) {
      TreeNode *rightChild = new TreeNode(data);
      currNode->right = rightChild;
      pn.emplace(rightChild);
    }
  }

  return root;
}

void printTree(TreeNode *root) {
  queue<TreeNode *> pn;
  pn.emplace(root);
  while (!pn.empty()) {
    TreeNode *currNode = pn.front();
    pn.pop();
    printf("%d: ", currNode->val);

    if (currNode->left) {
      printf("%d, ", currNode->left->val);
      pn.emplace(currNode->left);
    }

    if (currNode->right) {
      printf("%d", currNode->right->val);
      pn.emplace(currNode->right);
    }

    printf("\n");
  }
}