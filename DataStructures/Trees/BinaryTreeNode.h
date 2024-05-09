template <typename T>
class BTreeNode {
   public:
    T data;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BTreeNode() {
        delete left;
        delete right;
    }
}
