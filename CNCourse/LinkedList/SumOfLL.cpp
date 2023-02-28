#include<iostream>
using namespace std;
#include "CommonFunctions.cpp" 

int sumOfLL(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}
int main() {
    Node* head = takeInput();
    cout << sumOfLL(head) << endl;
}