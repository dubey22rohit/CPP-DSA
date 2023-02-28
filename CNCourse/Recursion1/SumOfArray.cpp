#include<iostream>
using namespace std;

int arrSum(int a[], int n){
	if(n == 0){
		return 0;
	}
	int smallAns = a[0] + arrSum(a + 1, n - 1);
	return smallAns;
}
int main(){
	int a[] = {1,2,3,4,5};
	cout << arrSum(a, 5);
}