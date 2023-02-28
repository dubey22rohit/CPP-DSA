#include<iostream>
using namespace std;

int firstIndex(int *a, int n, int x){
	if(n == 0){
		return -1;
	}

	if(a[0] == x){
		return 0;
	}

	int smallAns = firstIndex(a + 1, n - 1, x);

	if(smallAns == -1){
		return -1;
	}else{
		return smallAns + 1;
	}

	
}
int main(){
	int a[] = {1,2,3,2,5,4,6,4};
	cout << "First Occurance" << firstIndex(a, 8, 4);	
}