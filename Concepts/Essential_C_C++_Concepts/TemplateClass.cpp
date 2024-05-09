#include <iostream>
using namespace std;

template <class T>
class Arithmetic {
   private:
    T a;
    T b;

   public:
    // Arithmetic(T a, T b) {
    //     this->a = a;
    //     this->b = b;
    // }
    Arithmetic(T a, T b);

    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add() {
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::sub() {
    T c;
    c = a - b;
    return c;
}

int main() {
    Arithmetic<int> ar(10, 5);
    Arithmetic<float> af(15.5, 12.5);
    Arithmetic<char> ac('A', 'B');

    cout << "Int add: " << ar.add() << endl;
    cout << "Int sub: " << ar.sub() << endl;

    cout << "Float add: " << af.add() << endl;
    cout << "Float sub: " << af.sub() << endl;

    cout << "Char add: " << (int)ac.add() << endl;
    cout << "Char sub: " << (int)ac.sub() << endl;
}