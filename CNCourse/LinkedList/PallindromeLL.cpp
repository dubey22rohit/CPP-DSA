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

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p1 = NULL;
    Node *p2 = head;
    while (p2 != NULL)
    {
        Node *p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    return p1;
}

bool checkPallindrome(Node *head)
{
    // O(n) -> Time
    // O(1) -> Space
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *temp = head;
    Node *mp = midPoint(temp);
    mp = mp->next;//Because we're assuming the i - 1 th position to be the midpoint
    Node *rev = reverseLL(mp);
    
    while (rev != NULL)
    {
        if (temp->data != rev->data)
        {
            return false;
        }
        temp = temp->next;
        rev = rev->next;
    }
    return true;
}

int main()
{
    Node *head = takeInput();
    printLL(head);
    cout << endl << "IS PALLINDROME : " << checkPallindrome(head) << endl;
}