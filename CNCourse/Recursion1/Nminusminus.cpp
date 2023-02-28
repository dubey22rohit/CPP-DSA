#include<iostream>
using namespace std;

void infinite(int n){
	if(n < 0){
		return;
	}
	if(n == 0){
		cout << n;
		return;
	}
	infinite(n--);
	cout<< n << endl;
}

int main(){
	infinite(5);
}
//Solution Description
/*In function print when recursion call
 is being made,  n-- is being passed as input.
 Here we are using post decrement operator, 
 so argument passed to next function call is n and not n - 1.
 Thus there will be infinite recursion calls and StackOverflow exception.*/