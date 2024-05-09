#include <iostream>

template <typename T>
class ListNode {
   public:
    T data;
    ListNode* next;

    ListNode(T data) {
        this->data = data;
        next = nullptr;
    }

    ~ListNode() { delete next; }
};

ListNode<int>* createList() {
    int data;
    std::cin >> data;
    ListNode<int>*head = nullptr, *cn = nullptr, *nn = nullptr;
    while (data != -1) {
        nn = new ListNode<int>(data);
        if (head == nullptr) {
            head = nn;
            cn = head;
        } else {
            cn->next = nn;
            cn = nn;
        }
        std::cin >> data;
    }
    return head;
}

void printList(ListNode<int>* head) {
    ListNode<int>* t = head;
    while (t != nullptr) {
        std::cout << t->data << " ";
        t = t->next;
    }
}