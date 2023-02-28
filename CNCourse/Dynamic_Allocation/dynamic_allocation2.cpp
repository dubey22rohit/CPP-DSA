#include<bits/stdc++.h>
using namespace std;

int main(){
	int *p = new int;//Will create a memory on the heap of 4 bytes for int and 8 bytes for pointer on the stack.
	delete p ; //Clears heap memory as it is not destroyed automatically when the scope ends.The pointer memory will not be erased as it is static, it will be automatically deleted when the scope of this pointer variable ends.
	
	int *pa = new int[100];
	delete [] p;
}	
