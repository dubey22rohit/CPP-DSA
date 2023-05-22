#include <iostream>
using namespace std;
void print(int n) {
    // write your code here
    if (n == 1) {
        cout << n << " ";
        return;
    }

    print(n - 1);
    cout << n << " ";
}
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    print(n);
    return 0;
}
