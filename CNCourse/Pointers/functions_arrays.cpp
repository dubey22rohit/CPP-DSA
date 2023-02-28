#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int size) {
	cout << "Size of a in function since it is passed as a pointer " << sizeof(a) << endl;
	int ans = 0;
	for (int i = 0; i < size; i ++)
	{
		ans += a[i];
	}
	return ans;
}

int sum2(int *a, int size) {
	int ans = 0;
	for (int i = 0; i < size; i ++)
	{
		ans += a[i];
	}
	return ans;
}

//sum and sum2 are the same functions, size array is essentially passed as a pointer to the function it does not make a difference.

int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << sizeof(a) << endl;
	cout << sum(a, 10) << endl;
	cout << sum(a + 3, 7) << endl; // Works
	cout << sum2(a, 10) << endl;
}

