#include <iostream>
using namespace std;

// Ordered map: add, remove and search TC is O(logn)
class Hashmap {
 private:
  class TreeNode {
   public:
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, int val) {
      this->key = key;
      this->val = val;
      this->left = nullptr;
      this->right = nullptr;
    }
  };

  TreeNode* root;

  TreeNode* putHelper(int key, int value, TreeNode* root) {
    if (!root) {
      TreeNode* nn = new TreeNode(key, value);
      return nn;
    }
    if (root->key < key) {
      root->right = putHelper(key, value, root->right);
    } else if (root->key > key) {
      root->left = putHelper(key, value, root->left);
    } else {
      root->val = value;
    }

    return root;
  }

  int getHelper(int key, TreeNode* root) {
    if (!root) {
      return -1;
    }
    if (key > root->key) {
      return getHelper(key, root->right);
    } else if (key < root->key) {
      return getHelper(key, root->left);
    }

    return root->val;
  }

  TreeNode* getSuccessor(TreeNode* curr) {
    curr = curr->right;
    while (curr && curr->left) {
      curr = curr->left;
    }
    return curr;
  }

  TreeNode* removeHelper(int key, TreeNode* root) {
    if (!root) {
      return root;
    }
    if (key > root->key) {
      root->right = removeHelper(key, root->right);
    } else if (key < root->key) {
      root->left = removeHelper(key, root->left);
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

      TreeNode* succ = getSuccessor(root);
      root->key = succ->key;
      root->val = succ->val;
      root->right = removeHelper(succ->key, root->right);
    }

    return root;
  }

 public:
  Hashmap() { root = nullptr; }

  void put(int key, int value) {
    TreeNode* temp = root;
    TreeNode* newTree = putHelper(key, value, temp);
    this->root = newTree;
    return;
  }

  int get(int key) { return getHelper(key, root); }

  void remove(int key) {
    TreeNode* temp = root;
    TreeNode* newTree = removeHelper(key, temp);
    root = newTree;
    return;
  }
};

int main() {
  Hashmap obj;

  obj.put(25, 120);
  obj.put(35, 140);
  obj.put(15, 160);
  obj.put(5, 180);

  cout << obj.get(25) << endl;
  cout << obj.get(5) << endl;
  cout << obj.get(15) << endl;
  cout << obj.get(35) << endl;

  obj.remove(35);
  obj.remove(15);

  cout << "\n After Delete: \n";
  cout << obj.get(15) << endl;
  cout << obj.get(35) << endl;

  return 0;
}