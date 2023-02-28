#include<iostream>
using namespace std;

string reverseString(char *s){
    if(s[0] == '\0'){
        return "";
    }
    return reverseString(s + 1) + s[0];
}

int main(){
    char a[100];
    cin >> a;
    string rev = reverseString(a);
    cout << rev;
}