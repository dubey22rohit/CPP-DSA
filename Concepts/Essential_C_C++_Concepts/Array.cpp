#include <iostream>
using namespace std;

int main() {
    int A[10] = {2, 4, 6, 8, 10};
    cout << sizeof(A) << endl;  // 4(Size of an Int) * 10 = 40 bytes
    printf("%d\n", A[9]);       // Will print 0(Default value if not specified)
    cout << A[10] << endl;      // Will print garbage as len(A) = 10

    // Accessing elements
    // 1)For loop
    cout << "For loop : " << endl;
    for (int i = 0; i < 10; i++) {
        cout << A[i] << endl;
    }

    // 2)For each loop
    cout << "For EACH loop : " << endl;
    for (int x : A) {
        cout << x << endl;
    }

    int n;
    cout << "Enter size" << endl;
    cin >> n;
    int B[n];
    B[0] = 2;

    cout << "Variable length array";
    for (int x : B) {
        cout << x << endl;
    }

    return 0;
}