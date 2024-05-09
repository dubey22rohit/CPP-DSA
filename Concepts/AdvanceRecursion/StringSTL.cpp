#include <iostream>
using namespace std;

int main() {
    string s = "abc";

    getline(cin, s);

    cout << s << endl;
    cout << s[0] << endl;
    s[0] = 'z';
    cout << s << endl;

    string s1;
    s1 = "def";
    cout << s1 << endl;
    cout << s << endl;

    string s2 = s + s1;
    cout << s2 << endl;

    cout << s.size() << endl;
    cout << s.length() << endl;

    cout << s.substr(3) << endl;
    cout << s.substr(2, 3) << endl;
    cout << s.find("nin") << endl;

    string *sp = new string;
    *sp = "def";
    cout << sp << endl;
    cout << *sp << endl;

    return 0;
}