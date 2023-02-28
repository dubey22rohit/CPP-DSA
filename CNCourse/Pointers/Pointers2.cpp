#include<iostream>
using namespace std;

int main(){
	int i = 10;
	int *p = &i;
	
	cout<<sizeof(p)<<endl;
	cout<<i<<endl;
	cout<<"ADDRESS"<<p<<endl;
	cout<<"VALUE USING DEFERENCE OPERATOR "<<*p<<endl;
	
	i++;
	
	cout<<i<<endl;
	cout<<*p<<endl;
	
	int a = *p; //or i
	a++;
	cout<<a<<endl;
	cout<<*p<<endl;
	
	i = 12;
	cout<<i<<endl;
	cout<<*p<<endl;
	
	*p = 23;		
	cout<<i<<endl;
	cout<<*p<<endl;
	
	
}
