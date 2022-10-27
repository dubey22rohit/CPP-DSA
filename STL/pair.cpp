#include <iostream>
using namespace std;

int main() {
    pair<int, char> p;
    p = make_pair(2, 'b');

    pair<int, char> p2(1, 'a');

    cout << p.first << " " << p.second << endl;
    cout << p2.first << " " << p2.second << endl;

    return 0;
}