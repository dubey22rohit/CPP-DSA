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

    string *s3 = new string;
    *s3 = "def";
    cout << s3 << endl;   // Address
    cout << *s3 << endl;  // Value

    string s4;
    // cin >> s;//cin breaks at space, so we can't enter strings with spaces,
    // for that we use:
    getline(cin, s4);
    cout << s4 << endl;
    cout << s4[0] << endl;  // Works like an array as well

    string s5 = s3 + s4;  // Can concat 2 strings
    cout << s5 << endl;

    s3 += s4;  // Works as well
    cout << s3 << endl;

    cout << "Size: " << s4.size() << endl;
    cout << "Size: " << s4.substr(3) << endl;  // get everything after 3rd char
    cout << "Size: " << s4.substr(3, 3)
         << endl;  // get 3 more chars after 3rd char, substr(si,len)

    cout << s.find("def") << endl;

    return 0;
}