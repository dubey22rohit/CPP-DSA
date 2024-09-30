#include <iostream>
#include <queue>
#include <vector>

#include "../Helpers/TreeNode.h"

using namespace std;
vector<double> findLevelAverages(TreeNode* root) {
  vector<double> result;
  if (!root) {
    return result;
  }

  queue<TreeNode*> pn;
  pn.push(root);

  while (!pn.empty()) {
    int levelsize = pn.size();
    double avg = 0;
    for (int i = 0; i < levelsize; i++) {
      TreeNode* f = pn.front();
      pn.pop();

      avg += f->val;

      if (f->left) {
        pn.push(f->left);
      }

      if (f->right) {
        pn.push(f->right);
      }
    }
    result.push_back(avg / levelsize);
  }
  return result;
}

int main() {
  TreeNode* root = createTree();
  vector<double> ans = findLevelAverages(root);
  cout << "\nANS:\n";
  for (auto a : ans) {
    cout << a << ", ";
  }
  return 0;
}