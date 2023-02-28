#include<iostream>
using namespace std;

int main(){
	int i = 10;
	cout<<&i<<endl;
	int *p = &i;
	
	//Prints the address of the variable
	cout<<p<<endl;
	
	//Deference operator(used to get value from address)
	cout<<*p<<endl;
}
