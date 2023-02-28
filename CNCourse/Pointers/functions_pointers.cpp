#include<bits/stdc++.h>
using namespace std;

void print(int *p){
	cout << *p <<  endl; 
	cout<<endl;
	cout<<p<<endl;
}

void increment(int *p){
	p = p + 1;
}

void increment2(int *p){
	(*p)++;
}
int main(){
	int a = 10;
	int *p = &a;
	cout<<"Address of A"<<&a<<endl;
	print(p);
	
	cout<<p<<endl;
	increment(p);//Value of p won't change b/c we are passing by value.
	cout<<p<<endl;
	
	cout<<*p<<endl;
	increment2(p);//Value stored at the address pointed by p (i.e) a will change as we are passing by reference. 
	cout<<*p<<endl;
	
}
