class ListNode {
   public:
    int val;
    ListNode* next;

    ListNode() {
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};