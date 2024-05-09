#include <iostream>

#include "ListNode.cpp"
using namespace std;

int listLength(ListNode<int>* head) {
    int len = 0;
    ListNode<int>* temp = head;
    while (temp->next != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}

ListNode<int>* reverseList(ListNode<int>* head) {
    ListNode<int>*p = head, *q = nullptr, *r = nullptr;
    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

ListNode<int>* listMid(ListNode<int>* head) {
    ListNode<int>*fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(ListNode<int>* head) {
    ListNode<int>* temp = head;
    ListNode<int>* mid = listMid(head);
    ListNode<int>* revMid = reverseList(mid);
    while (revMid->next != nullptr) {
        if (temp->data != revMid->data) {
            return false;
        }
        temp = temp->next;
        revMid = revMid->next;
    }
    return true;
}

int main() {
    ListNode<int>* head = createList();
    printList(head);
    bool isPd = isPalindrome(head);
    cout << "\n"
         << "isPalindrome: " << isPd;
    return 0;
}