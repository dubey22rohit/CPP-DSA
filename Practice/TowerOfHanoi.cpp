#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char aux, char dest) {
    if (n <= 0) {
        return;
    }

    towerOfHanoi(n - 1, src, dest, aux);
    cout << src << " " << dest << endl;
    towerOfHanoi(n - 1, aux, src, dest);
}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}