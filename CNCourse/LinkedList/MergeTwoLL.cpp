#include <iostream>
using namespace std;
#include "CommonFunctions.cpp"

Node *mergeTwoLL(Node *h1, Node *h2)
{
    Node *fh, *ft = NULL;
    if (h1 == NULL)
    {
        return h2;
    }
    if(h2 == NULL)
    {
        return h1;
    }
    if (h1->data < h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }
    else
    {
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            ft->next = h1;
            ft = h1;
            h1 = h1->next;
        }
        else
        {
            ft->next = h2;
            ft = h2;
            h2 = h2->next;
        }
    }
    if (h2 == NULL)
    {
        ft->next = h1;
    }
    else
    {
        ft->next = h2;
    }
    return fh;
}

int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    // printLL(head);
    Node *sorted = mergeTwoLL(head1, head2);
    printLL(sorted);
}