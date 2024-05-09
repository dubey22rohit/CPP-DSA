template <typename T>
class BTNode {
   public:
    T data;
    BTNode* lchild;
    BTNode* rchild;

    BTNode(T data) {
        this->data = data;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }
    ~BTNode() {
        delete lchild;
        delete rchild;
    }
};