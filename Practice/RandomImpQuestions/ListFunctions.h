#include <iostream>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode() {
        this->data = 0;
        this->next = nullptr;
    }
    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~ListNode() { delete next; }
};

ListNode* takeInput() {
    ListNode *head = nullptr, *ch = nullptr, *curr = nullptr;
    int data;
    cin >> data;
    while (data != -1) {
        curr = new ListNode(data);
        if (head == nullptr) {
            head = curr;
            ch = head;
        } else {
            ch->next = curr;
            ch = curr;
        }
        cin >> data;
    }
    return head;
}

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}