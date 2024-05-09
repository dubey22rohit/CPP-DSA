#include <iostream>

#include "ListNode.cpp"
using namespace std;

int listLength(ListNode<int>* head) {
    ListNode<int>* t = head;
    int len = 0;
    while (t != nullptr) {
        len++;
        t = t->next;
    }
    return len;
}

ListNode<int>* ShiftLL(ListNode<int>* head, int k) {
    int move = listLength(head) - k;
    ListNode<int>*oh = head, *hp = head;
    for (int i = 0; i < move; i++) {
        hp = head;
        head = head->next;
    }
    cout << "\nCurrent head value: " << head->data << endl;
    cout << "\nCurrent head pointer value: " << hp->data << endl;
    hp->next = nullptr;
    ListNode<int>* nhp = head;
    cout << "\nInitial new head pointer value: " << nhp->data << endl;
    while (nhp->next != nullptr) {
        nhp = nhp->next;
    }
    cout << "\nFinal new head pointer value: " << nhp->data << endl;
    nhp->next = oh;
    return head;
}

int main() {
    ListNode<int>* head = createList();
    printList(head);
    ListNode<int>* shead = ShiftLL(head, 2);
    cout << "\nAfter shift:\n";
    printList(shead);
    return 0;
}