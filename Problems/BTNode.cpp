template <typename T>
class BTNode {
   public:
    T data;
    BTNode* lchild;
    BTNode* rchild;

    BTNode() {
        lchild = nullptr;
        rchild = nullptr;
    }

    BTNode(T data) {
        this->data = data;
        lchild = nullptr;
        rchild = nullptr;
    }

    ~BTNode() {
        delete lchild;
        delete rchild;
    }
};