#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// The question describes the range of node->val between -1000 and 1000, so to
// check for null values we're using 1001
// which might not be the best way but we can come back to it later

class Codec {
public:
  string serialize(TreeNode *root) {
    if (!root) {
      return "";
    }
    queue<TreeNode *> q;
    q.push(root);
    string ans = to_string(root->val) + ",";
    while (!q.empty()) {
      TreeNode *currNode = q.front();
      q.pop();
      if (currNode->left) {
        q.push(currNode->left);
        ans.append(to_string(currNode->left->val));
      } else {
        ans.append("1001");
      }
      ans.append(",");

      if (currNode->right) {
        q.push(currNode->right);
        ans.append(to_string(currNode->right->val));
      } else {
        ans.append("1001");
      }
      ans.append(",");
    }

    return ans;
  }
  TreeNode *deserialize(string data) {
    if (data.size() == 0) {
      return NULL;
    }
    stringstream intData(data);
    string line;
    vector<int> dataArr;
    while (getline(intData, line, ',')) {
      dataArr.push_back(stoi(line));
    }
    int rootData = dataArr[0];
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pn;
    pn.push(root);
    int i = 1;
    while (!pn.empty()) {
      TreeNode *fn = pn.front();
      pn.pop();

      if (dataArr[i] != 1001) {
        TreeNode *ln = new TreeNode(dataArr[i]);
        pn.push(ln);
        fn->left = ln;
      }
      i++;

      if (dataArr[i] != 1001) {
        TreeNode *rn = new TreeNode(dataArr[i]);
        pn.push(rn);
        fn->right = rn;
      }
      i++;
    }

    return root;
  }
};

int main() {
  TreeNode *root = createTree();
  printTree(root);
  Codec ser, deser;
  string serialized = ser.serialize(root);
  cout << endl;
  // stringstream data(serialized);
  // string line;
  // while (getline(data, line, ',')) {
  // cout <<line << endl;
  TreeNode *deserialized = deser.deserialize(serialized);
  printTree(deserialized);

  return 0;
}
