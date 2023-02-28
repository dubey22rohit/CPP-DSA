#include<iostream>
using namespace std;

int binarySearch(int *a, int s, int e, int k){
	if(s >= e){
		return -1;
	}
	int mid = s + (e - s)/2;
	if(a[mid] == k){
		return mid;
	}
	if(k < a[mid]){
		return binarySearch(a, s, mid - 1, k);
	}else{
		return binarySearch(a, mid + 1, e, k);
	}


}
int main(){
	int arr[] = {1,2,3,4,5};
	cout << binarySearch(arr,0,5,5);	
}