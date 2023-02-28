#include <iostream>
using namespace std;

long long int decToBin(int a)
{
    if (a == 0)
    {
        return 0;
    }
    return (a % 2 + 10*decToBin(a/2));
}

char* decToBinStr(int a, char *r){
    if(a == 0){
        return r;
    }
    r = a % 2 + r;
    return decToBinStr(a/2, r);
}

int main()
{
    int a;
    cin >> a;
    int ans = decToBin(a);
    char* ansStr = decToBinStr(a, "");
    cout << ans << endl;
    cout << ansStr;
}