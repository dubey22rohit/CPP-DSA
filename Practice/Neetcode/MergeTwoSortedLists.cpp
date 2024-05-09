#include <iostream>

#include "ListNode.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *temp, *dm;
    dm = new ListNode();
    temp = dm;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1) {
        temp->next = list1;
    }
    if (list2) {
        temp->next = list2;
    }

    return dm->next;
}

int main() {
    ListNode* list1 = createList();
    printList(list1);
    ListNode* list2 = createList();
    printList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    printList(mergedList);
    return 0;
}