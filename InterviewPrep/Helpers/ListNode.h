#include <iostream>
using namespace std;

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

ListNode* createList() {
  int data;
  cin >> data;
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
    cin >> data;
  }
  return head;
}

void printList(ListNode* head) {
  ListNode* temp = head;
  while (temp != nullptr) {
    cout << temp->val;
    temp = temp->next;
  }
  cout << endl;
}