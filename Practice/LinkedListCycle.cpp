#include <iostream>
#include <unordered_map>

#include "ListNode.h"
using namespace std;

//* https://leetcode.com/problems/linked-list-cycle/description/

// Good solution, not accepted by leetcode though
// They're maintinaing a pos variable internally
// which we can't access, so some testcases fail
//  bool hasCycle(ListNode* head) {
//      unordered_map<int, ListNode*> hm;
//      while (head != nullptr) {
//          if (hm.find(head->val) != hm.end()) {
//              return true;
//          }
//          hm[head->val] = head;
//          head = head->next;
//      }
//      return false;
//  }
bool hasCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

int main() { return 0; }