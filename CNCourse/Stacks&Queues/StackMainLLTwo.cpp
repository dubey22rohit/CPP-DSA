#include <iostream>
using namespace std;
#include "../LinkedList/CommonFunctions.cpp"
#include "StackUsingLLTwo.cpp"
int main() {
    StackUsingLLTwo s;
    for (int i = 1; i <= 5; i++) {
        s.push(i * 15);
    }
    cout << endl << "Size : " << s.getSize() << endl;
    cout << "Top : " << s.top() << endl;
    cout << "Complete LL : ";
    printLL(s.getHead());
    cout << endl;
    while (!s.isEmpty()) {
        cout << "Popped el : " << s.pop() << endl;
    }
    cout << "Complete LL After popping: ";
    printLL(s.getHead());
}