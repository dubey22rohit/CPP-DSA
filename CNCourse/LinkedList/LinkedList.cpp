#include <iostream>
using namespace std;
#include "Node.cpp"

void printLL(Node *head){
    Node *temp = head;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    temp = head;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* takeInputOptimized(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *currNode = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            currNode = head;
        }else{
            currNode->next = newNode;
            currNode = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* insertNode(Node* head, int pos, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if(pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < pos - 1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int lengthOfLL(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void printIthNode(Node* head, int i){
    int x = 0;
    Node* temp = head;
    while(x < i){
        temp = temp->next;
        x++;
    }
    cout << temp->data;
}

Node* deleteNode(Node* head, int pos){
    Node* temp = head;
    int x = 0;
    while(x < pos){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

int main(){
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *n2 = new Node(2);
    Node *n3 = new Node(3); 
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4; 
    n4->next = n5;
    n5->next = n6; 

    //printLL(head);
    //cout << endl;
    //Node *headfn = takeInput();
    Node *headfn = takeInputOptimized();
    printLL(headfn);
    int i, data;
    cin >> i >> data;
    headfn = insertNode(headfn,i,data);
    printLL(headfn);
    cout << endl;
    cout << "LENGTH : " << lengthOfLL(headfn) << endl;
    cout << "Ith Node : ";
    printIthNode(headfn, 2);

}
