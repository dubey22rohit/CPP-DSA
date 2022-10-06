#include <iostream>
using namespace std;

class Rectangle {
   private:
    int length;
    int breadth;

   public:
    Rectangle() {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b);
    int area();
    int perimeter();
    void setLength(int l);
    void setBreadth(int b);
    int getLength();
    int getBreadth();
};

Rectangle::Rectangle(int l, int b) {
    this->length = l;
    this->breadth = b;
}

int Rectangle::area() { return length * breadth; }

int Rectangle::perimeter() { return 2 * (length + breadth); }

void Rectangle::setLength(int l) { this->length = l; }

void Rectangle::setBreadth(int b) { this->breadth = b; }

int Rectangle::getLength() { return length; }

int Rectangle::getBreadth() { return breadth; }

int main() {
    Rectangle r{10, 5};

    cout << "Length" << r.getLength() << endl;
    cout << "Breadth" << r.getBreadth() << endl;
    cout << "area" << r.area() << endl;
    cout << "perimeter" << r.perimeter() << endl;

    cout << "Changing length and breadth" << endl;

    r.setLength(100);
    r.setBreadth(150);

    cout << "Length after changing l and b" << r.getLength() << endl;
    cout << "Breadth after changing l and b" << r.getBreadth() << endl;
    cout << "Area after changing l and b" << r.area() << endl;
    cout << "perimeter after changing l and b" << r.perimeter() << endl;
}