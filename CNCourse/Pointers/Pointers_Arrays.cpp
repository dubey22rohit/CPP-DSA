#include<iostream>
using namespace std;

int main(){
	int a[10];
	cout<<"1 : "<<a<<endl;
	cout<<"2 : "<<&a[0]<<endl;
	
	a[0] = 5;
	a[1] = 10;
	cout<<"3 : "<<*a<<endl;
	cout<<"4 : "<<*(a + 1)<<endl;
	
	int *p = &a[0];
	cout<<"5 : "<< a <<endl;
	cout<<"6 : "<< p <<endl;
	
	cout<<endl;
	
	cout<<"7 : "<<&a<<endl;
	cout<<"8 : "<<&p<<endl;
	
	cout<<"9 : "<<sizeof(p)<<endl;
	cout<<"10 : "<<sizeof(a)<<endl;
	
	cout<<"11 : "<<*p<<endl;
	p = p + 1;//Works
//	a = a + 1;//Doesn't work
	cout<<"12 : "<<*p<<endl;
	
	
}
