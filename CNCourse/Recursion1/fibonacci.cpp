#include<iostream>
using namespace std;

int fibSum(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	int smallAns = fibSum(n - 1) + fibSum(n - 2);
	return smallAns;

}
int main(){
	cout << fibSum(5);
}
