#include <iostream>

#include "ListNode.cpp"
using namespace std;
// ll1: 2->4->7->1, 1: most significant, so the number is 1742
// ll2: 9->4->5, number: 549

ListNode<int>* listsSum(ListNode<int>* ll1, ListNode<int>* ll2) {
    ListNode<int>*nlh = nullptr, *cnl = nullptr, *nn = nullptr;
    int carry = 0, cs = 0;
    while (ll1 != nullptr && ll2 != nullptr) {
        cs = ll1->data + ll2->data + carry;
        carry = cs / 10;
        nn = new ListNode<int>(cs % 10);
        if (nlh == nullptr) {
            nlh = nn;
            cnl = nlh;
        } else {
            cnl->next = nn;
            cnl = nn;
        }
        ll1 = ll1->next;
        ll2 = ll2->next;
    }

    while (ll1 != nullptr) {
        nn = new ListNode<int>(ll1->data + carry);
        cnl->next = nn;
        cnl = nn;
        ll1 = ll1->next;
        carry = 0;
    }

    while (ll2 != nullptr) {
        nn = new ListNode<int>(ll2->data + carry);
        cnl->next = nn;
        cnl = nn;
        ll2 = ll2->next;
        carry = 0;
    }

    return nlh;
}

ListNode<int>* addTwoNumber(ListNode<int>* ll1, ListNode<int>* ll2) {
    ListNode<int>*ans = nullptr, *ansp = nullptr, *nn = nullptr;
    int s1 = 0, s2 = 0, sum = 0, carry = 0;
    while (ll1 != nullptr || ll2 != nullptr || carry != 0) {
        if (ll1 == nullptr) {
            s1 = 0;
        } else {
            s1 = ll1->data;
            ll1 = ll1->next;
        }

        if (ll2 == nullptr) {
            s2 = 0;
        } else {
            s2 = ll2->data;
            ll2 = ll2->next;
        }

        sum = s1 + s2 + carry;
        carry = sum / 10;
        int rem = sum % 10;
        nn = new ListNode<int>(rem);
        if (ans == nullptr) {
            ans = nn;
            ansp = ans;
        } else {
            ansp->next = nn;
            ansp = nn;
        }
    }
    return ans;
}

int main() {
    ListNode<int>* ll1 = createList();
    ListNode<int>* ll2 = createList();
    printList(ll1);
    cout << "\n";
    printList(ll2);
    // ListNode<int>* listSum = listsSum(ll1, ll2);
    ListNode<int>* listSum2 = addTwoNumber(ll1, ll2);
    // cout << "\nList Sum 1:\n";
    // printList(listSum);
    cout << "\nList Sum 2:\n";
    printList(listSum2);
    return 0;
}