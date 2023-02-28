#include<bits/stdc++.h>
using namespace std;

void increment(int n){
	n++;//Passing n by value, so increment.n = main.i and after that making a change in increment.n does not reflect in i(since the have different memories)
}

void increment2(int& n){
	n++;//Passing n as a reference variable, so &increment.n == main.i and now making a change in increment.n will change i(as both of them point to the same memory)
}

//Bad practice
int& f(int n){
	int a = n;
	return a;
}

//Bad practice
int* f2(){
	int i	=	10;
	return &i;
}

int main(){

	int *p = f2();//Since &i returned from f2 will be a local variable address, p can point to something garbage after scope of f2 ends;
	
	int i = 10;
	
	int& k1 = f(i);//Since f is returning something which lies in its local scope so referencing k can lead to unpredctible results
	
	increment(i);
	cout<<"Increment i : "<<i<<endl;
	
	increment2(i);
	cout<<"Increment2 i : "<<i<<endl;
	
	int& j = i;
	
	i++;
	cout<<j<<endl;
	
	j++;
	cout << i << endl;
	
	int k = 150;
	j = k;
	cout<<i<<endl;
	cout<<j<<endl;
}
