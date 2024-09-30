#include <iostream>
#include <queue>

#include "../Helpers/TreeNode.h"
using namespace std;

// DFS
int findDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }
  int lh = findDepth(root->left);
  int rh = findDepth(root->right);

  return 1 + min(lh, rh);
}

// BFS
int findDepthBFS(TreeNode* root) {
  int minDepth = 0;
  if (!root) {
    return minDepth;
  }
  queue<TreeNode*> pn;
  pn.push(root);

  while (!pn.empty()) {
    minDepth++;
    int levelsize = pn.size();
    for (int i = 0; i < levelsize; i++) {
      TreeNode* f = pn.front();
      pn.pop();

      if (!f->left & !f->right) {
        return minDepth;
      }

      if (f->left) {
        pn.push(f->left);
      }

      if (f->right) {
        pn.push(f->right);
      }
    }
  }
  return minDepth;
}

int main() {
  TreeNode* root = createTree();
  int minDepth = findDepth(root);
  int minDepthBFS = findDepthBFS(root);
  cout << minDepth << endl;
  cout << minDepthBFS;
  return 0;
}