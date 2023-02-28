#include <iostream>
using namespace std;
#include "StackUsingArray.cpp"
int main()
{   
    Stack<char> s;
    for (int i = 100; i <= 105; i++)
    {
        s.push(i);
        cout << "size : " << s.size() << endl;
    }
    cout << "Top : " << s.top();
    cout << endl;
    while (!s.isEmpty())
    {
        cout << s.pop() << " ";
    }
}