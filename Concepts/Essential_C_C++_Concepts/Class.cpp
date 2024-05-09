#include <iostream>
using namespace std;

class Rectangle {
   private:
    int length;
    int breadth;

   public:
    Rectangle(int l, int b) {
        this->length = l;
        this->breadth = b;
    }

    int area() { return length * breadth; }

    int perimeter() { return 2 * (length + breadth); }
};

int main() {
    Rectangle r{10, 5};
    cout << "area : " << r.area() << endl;
    cout << "perimeter : " << r.perimeter() << endl;
}