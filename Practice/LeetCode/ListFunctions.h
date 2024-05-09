#include "ListNode.h"
using namespace std;

ListNode *takeInputOptimized() {
    int data;
    cin >> data;
    ListNode *head = NULL;
    ListNode *currNode = NULL;
    while (data != -1) {
        ListNode *newNode = new ListNode(data);
        if (head == NULL) {
            head = newNode;
            currNode = head;
        } else {
            currNode->next = newNode;
            currNode = newNode;
        }
        cin >> data;
    }
    return head;
}

void printLL(ListNode *head) {
    ListNode *temp = head;
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    temp = head;
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}