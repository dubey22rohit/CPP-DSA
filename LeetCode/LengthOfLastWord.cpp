#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;
    int i = s.length() - 1;
    while (s[i] == ' ') {
        i--;
    }
    while (s[i] != ' ') {
        if (i <= 0) {
            len++;
            break;
        }
        len++;
        i--;
    }
    return len;
}

int main() {
    string s = "Hello world";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "Eardtree";

    cout << "s last word length: " << lengthOfLastWord(s) << endl;
    cout << "s2 last word length: " << lengthOfLastWord(s2) << endl;
    cout << "s3 last word length: " << lengthOfLastWord(s3) << endl;

    return 0;
}