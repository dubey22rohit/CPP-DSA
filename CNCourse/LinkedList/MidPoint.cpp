#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

Node *midPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = takeInput();
    printLL(head);
    Node *mp = midPoint(head);
    cout << "Mid Point : " << mp->data;
    printLL(mp);
}