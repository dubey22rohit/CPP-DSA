#include <iostream>

#include "ListNode.cpp"
using namespace std;

ListNode<int>* mergeLL(ListNode<int>* l1, ListNode<int>* l2) {
    ListNode<int>*nh, *cn, *nn;
    if (l1->data < l2->data) {
        nh = new ListNode<int>(l1->data);
        cn = nh;
        l1 = l1->next;
    } else {
        nh = new ListNode<int>(l2->data);
        cn = nh;
        l2 = l2->next;
    }
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            nn = new ListNode<int>(l1->data);
            cn->next = nn;
            cn = nn;
            l1 = l1->next;
        } else {
            nn = new ListNode<int>(l2->data);
            cn->next = nn;
            cn = nn;
            l2 = l2->next;
        }
    }

    while (l1 != nullptr) {
        nn = new ListNode<int>(l1->data);
        cn->next = nn;
        cn = nn;
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        nn = new ListNode<int>(l2->data);
        cn->next = nn;
        cn = nn;
        l2 = l2->next;
    }
    return nh;
}

int main() {
    ListNode<int>* head1 = createList();
    ListNode<int>* head2 = createList();
    printList(head1);
    cout << "\n";
    printList(head2);
    cout << "\nMerged List:\n";
    ListNode<int>* nl = mergeLL(head1, head2);
    printList(nl);
    return 0;
}