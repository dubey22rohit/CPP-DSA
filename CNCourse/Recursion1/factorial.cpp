#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
	if(n==0){
		return 1;
	}
	int smallAns = factorial(n-1);
	return n * smallAns;
}

int main(){
	int n;
	cin >> n;
	int op = factorial(n);
	cout << op;
}
