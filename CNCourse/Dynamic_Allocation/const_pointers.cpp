#include<iostream>
using namespace std;

int main(){
	const int i = 10;
	const int *p = &i;
	
	int j = 14;
	const int* pj = &j;
	
	cout << *pj << endl;//(*pj)++ won't work. 
	j++;
	cout<<j<<endl;
	
	int i2 = 20;
	int j2 = 30;
	
	int const *p2 = &i2;//Works, here p2 is a pointer to a constant variable, p2 is not constant
	p2 = &j2; //Will also work
	(*p2)++; // Won't work.
	
	int * const p3 = &i2;//Now the pointer itself is constant.
	p2 = &j2; //Won't work
	(*p2)++; //Works as int j2 is not constant
	
	int const * const p4 = &i;//Constant pointer to a constant variable.
	p3 = &j2; //Won't work
	(*p3)++; //Won't work
	
}
