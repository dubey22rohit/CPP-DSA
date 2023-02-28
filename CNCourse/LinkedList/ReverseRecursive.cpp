#include<iostream>
using namespace std;
#include "CommonFunctions.cpp"

Node* reverseLLRecursive(Node* head){
    if(head == NULL || head->next== NULL){
        return head;
    }
    Node *p = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

int main(){
    Node* head = takeInput();
    printLL(head);
    cout<<endl;
    reverseLLRecursive(head);
    printLL(head);
}