#include<iostream>
using namespace std;

bool checkNumber(int a[], int n, int x){
	if(n == 0){
		return false;
	}

	if(a[0] == x){
		return true;
	}
	return checkNumber(a + 1, n - 1, x);
}

int main(){
	int a[] = {1,2,3,4,5};
	cout << checkNumber(a,5,2);
}