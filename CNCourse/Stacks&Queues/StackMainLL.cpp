#include <iostream>
using namespace std;
#include "../LinkedList/CommonFunctions.cpp"
#include "StackUsingLL.cpp"
int main() {
    StackUsingLL s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Size : " << s.getSize() << endl;
    cout << "TOP : " << s.top() << endl;
    cout << "Is Empty : " << s.isEmpty() << endl;
    cout << "Popped el : " << s.pop() << endl;
    cout << "Popped el : " << s.pop() << endl;
    cout << "Popped el : " << s.pop() << endl;
    cout << "Popped el : " << s.pop() << endl;
    cout << "Popped el : " << s.pop() << endl;
    cout << "Popped el : " << s.pop() << endl;
    printLL(s.getHead());
}