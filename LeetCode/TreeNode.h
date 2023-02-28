template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode() {
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(T val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};