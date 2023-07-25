#include <iostream>
class ListNode {
   public:
    int val;
    ListNode* next;

    ListNode() {
        this->val = -1;
        this->next = nullptr;
    }

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }

    ~ListNode() { this->next = nullptr; }
};

ListNode* createList() {
    int data;
    std::cin >> data;
    ListNode *head = nullptr, *temp = nullptr;
    while (data != -1) {
        ListNode* nn = new ListNode(data);
        if (head == nullptr) {
            head = nn;
            temp = head;
        } else {
            temp->next = nn;
            temp = nn;
        }
        std::cin >> data;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
