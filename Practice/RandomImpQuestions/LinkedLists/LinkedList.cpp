#include <iostream>

#include "Node.h"
using namespace std;

Node* createList() {
    int data;
    Node *head = nullptr, *tail = nullptr, *nn = nullptr;
    while (data != -1) {
        cin >> data;
        nn = new Node(data);
        if (head == nullptr) {
            head = nn;
            tail = nn;
        } else {
            tail->next = nn;
            tail = nn;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* t = head;
    while (t->next != nullptr) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

// Assuming that the list is 0 indexed
void insert(Node* head, int pos, int ele) {
    Node* t = head;
    for (int i = 0; i < pos - 1; i++) {
        t = t->next;
    }
    Node* nn = new Node(ele);
    nn->next = t->next;
    t->next = nn;
}

// Assuming that the list is 0 indexed
int deleteNode(Node* head, int ele) {
    Node* t = head;
    while (t->next->data != ele) {
        t = t->next;
    }
    cout << "\nCurrent T value: " << t->data << "\n";
    int deleted = t->next->data;
    t->next = t->next->next;
    return deleted;
}

int main() {
    Node* head = createList();
    printList(head);

    int pos, ele;
    cout << "\nEnter pos and element to insert: ";
    cin >> pos >> ele;
    insert(head, pos, ele);
    printList(head);

    cout << "\nEnter node to delete";
    int toDelete;
    cin >> toDelete;
    int deletednode = deleteNode(head, toDelete);
    cout << "\nDeleted node: " << deletednode << "\n";
    printList(head);

    return 0;
}