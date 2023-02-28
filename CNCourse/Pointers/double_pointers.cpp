#include<bits/stdc++.h>
using namespace std;

void increment1(int **p){
	p = p + 1;//Won't work, will make a change in its own copy, won't change the origianl copy.
}

void increment2(int **p){
	*p = *p + 1;//Will work and increment the value of address of i by 4.
}

void increment3(int **p){
	**p = **p + 1;//Will work and increment the value of i by 1.
}

int main(){
	int i = 10;
	int *p = &i;
	
	int **pp = &p;
	
	cout<<"Value of variable i : "<<i<<endl;
	cout<<"What is stored inside block p, i.e the address of i : "<<p<<endl;
	cout<<"What is stored inside block pp, i.e the address of p : "<<pp<<endl;
	
	cout<<endl;
	
	cout<<pp<<endl;
	cout<<&p<<endl;
	
	cout<<endl;

	cout << &i << endl;	
	cout << p << endl;
	cout << *pp << endl;

	
	cout<<endl;
	
	cout << i << endl;
	cout << *p << endl;
	cout << *(*pp) << endl;
	
	cout<<endl;
	
	//cout << increment1(pp) << endl;
	//cout << increment2(pp) << endl;
	//cout << increment3(pp) << endl;
}	
