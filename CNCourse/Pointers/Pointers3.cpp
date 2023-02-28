#include<bits/stdc++.h>
using namespace std;

int main(){
	float f = 10.5;
	float p = 2.5;
	
	float *ptr = &f;
	
	(*ptr)++;
	*ptr = p;
	
	cout<< *ptr << " " << " "<< f << " " <<p;
	
	int *ptr2 = 0;
	int a = 10;
	*ptr2 = a;
	cout<<*ptr2;
}
