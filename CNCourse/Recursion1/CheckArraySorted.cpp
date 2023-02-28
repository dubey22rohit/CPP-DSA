#include <iostream>
using namespace std;

bool checkSorted(int *arr, int n){
	if(n == 1 || n == 0){
		return true;
	}
	if(arr[0] > arr[1]){
		return false;
	}
	bool smallerSorted = checkSorted(arr + 1, n - 1);
	return smallerSorted;
}

bool checkSorted2(int a[], int n){
	if(n == 0 || n == 1){
		return true;
	}
	bool smallerSorted = checkSorted2(a + 1, n - 1);
	if(!smallerSorted){
		return false;
	}
	if(a[0] > a[1]){
		return false;
	}else{
		return true;
	}
}

int main(){
	int arr[] = {5,4,2,1,3};
	cout << checkSorted(arr,5);
}