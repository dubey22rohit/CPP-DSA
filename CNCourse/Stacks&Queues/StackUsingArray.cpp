#include <climits>
template <typename T>
class Stack
{
private:
    T *data;
    int ni;
    int cap;

public:
    Stack()
    {
        data = new T[5];
        ni = 0;
        cap = 5;
    }
    int size()
    {
        return ni;
    }
    bool isEmpty()
    {
        return (ni == 0);
    }
    void doubleCapacity()
    {
        T *temp = new T[cap * 2];
        for (int i = 0; i < cap; i++)
        {
            temp[i] = data[i];
        }
        cap *= 2;
        delete[] data;
        data = temp;
    }
    void push(T e)
    {
        if (ni == cap)
        {
            cout << "Double capacity called " << endl;
            doubleCapacity();
        }
        data[ni] = e;
        ni++;
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return 0;
        }
        ni--;
        return data[ni];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return 0;
        }
        return data[ni - 1];
    }
};