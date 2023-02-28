#include <iostream>
using namespace std;
#include "Node.cpp"

void printLL(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* takeInput()
{
    int data;
    cin >> data;
    Node* head = NULL;
    Node* currNode = NULL;
    while (data != -1)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            currNode = head;
        }
        else
        {
            currNode->next = newNode;
            currNode = newNode;
        }
        cin >> data;
    }
    return head;
}