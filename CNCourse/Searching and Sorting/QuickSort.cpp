#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int s, int e){
	int pivot = a[s];
	int count = 0;
	for(int i = s + 1;i <= e;i++){
		if(a[i] <= pivot ){
			count++;
		}
	}

	int pivotIndex = s + count;

	// swap(a[s],a[pivotIndex]);
	int temp = a[s];
	a[s] = a[pivotIndex];
	a[pivotIndex] = temp;

	int i = s, j = e;

	while(i <= pivotIndex && j >= pivotIndex){
		while(a[i] <= pivot){
			i++;
		}
		while(a[j] > pivot){
			j--;
		}
		if(i < pivotIndex && j > pivotIndex){
			// swap(a[i],a[j]);
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	return pivotIndex;
}

void quickSort(int a[], int s, int e){
	if(s >= e){
		return;
	}
	int pivot = partition(a, s, e);
	quickSort(a, s, pivot - 1);
	quickSort(a, pivot + 1, e);
}


int main(){
	// 
	int a[] = {5,1,4,2,3};
	quickSort(a,0, 4);
	for (int i = 0; i < 5; ++i)
	{
		cout << a[i] << " ";
	}
}