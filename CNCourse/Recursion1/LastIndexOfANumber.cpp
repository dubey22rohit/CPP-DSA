#include<iostream>
using namespace std;

int lastIndex(int a[], int n, int x){
	if(n == 0){
		return -1;
	}
	int smallAns = lastIndex(a + 1, n - 1, x);

	if(smallAns != -1){
		return smallAns + 1;
	}
	
	if(a[0] == x){
		return 0;
	}
	else{
		return -1;
	}
}
int main(){
	int a[] = {1,2,3,4,5,6,4,5};
	cout << lastIndex(a,8,4);
}