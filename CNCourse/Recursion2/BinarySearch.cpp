#include <iostream>
using namespace std;

int binarySearch(int *a, int s, int e, int x)
{
    if (s > e)
    {
        return -1;
    }
    int m = s + (e - s) / 2;
    if (a[m] == x)
    {
        return m;
    }
    if (a[m] < x)
    {
        return binarySearch(a, m + 1, e, x);
    }

    return binarySearch(a, s, m - 1, x);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int k;
    cin >> k;
    int l = sizeof(a) / sizeof(a[0]);
    int ans = binarySearch(a, 0, l, k);
    cout << ans;
}