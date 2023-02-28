#include <iostream>
using namespace std;

int length(char *s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        l++;
    }
    return l;
}
bool isPallindrome_helper(char *s, int st, int en)
{
    if (s[0] == '\0' || s[1] == '\0')
    {
        return true;
    }
    if (st >= en)
    {
        return true;
    }
    if (s[st] == s[en])
    {
        return isPallindrome_helper(s, st + 1, en - 1);
    }
    return false;
}
bool isPallindrome(char *s)
{
    int len = length(s);
    return isPallindrome_helper(s, 0, len - 1);
}

int main()
{
    char s[100];
    cin >> s;
    bool ans = isPallindrome(s);
    cout << ans;
}