#include<iostream>
using namespace std;

int multiply(int x, int y){
	if(y == 1){
		return x;
	}
	return x + multiply(x, y - 1);
}
int main(){
	cout<<multiply(3,4);	
}