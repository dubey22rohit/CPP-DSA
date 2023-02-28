#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

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
        p2->next = p1; //Main Reversal Step
        p1 = p2;
        p2 = p3;
    }
    return p1;
}

int main()
{
    Node *head = takeInput();
    printLL(head);
    Node *revLL = reverseLL(head);
    cout << "Reversed LL : ";
    printLL(revLL);
}