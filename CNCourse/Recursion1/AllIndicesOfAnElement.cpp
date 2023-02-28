#include<iostream>
using namespace std;

void allIndicesHelper(int a[], int currIndex, int n, int x, int[] op, int &k){
	if(currIndex == n){
		return -1;
	}
	if(a[0] == x){
		op[k] = currIndex;
		k++;
	}
	allIndicesHelper(a, currIndex + 1, n, x, op, k);

}
int allIndices(int a[], int n, int x, int op[]){
	int k = 0;
	return allIndicesHelper(a, 0, n, x,op,k);
	return k;
}
int main(){
	int a[] = {1,2,3,4,5,4,7};
	cout << allIndices(a, 7, 4);
	
}