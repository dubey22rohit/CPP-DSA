#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Rohit";
    string s1(s);  // Copy s in s1
    cout << s << endl;
    cout << s1 << endl;

    // slice
    string s2(s, 2, 4);
    cout << s2 << endl;

    // substring
    string s3 = s.substr(1, 4);
    cout << s3 << endl;

    // Checking if strings are equal
    if (s1.compare(s2) == 0) {
        cout << s1 << " is equal to " << s2 << endl;
    } else {
        cout << s1 << " is not equal to " << s2 << endl;
    }

    return 0;
}