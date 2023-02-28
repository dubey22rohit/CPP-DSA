#include<bits/stdc++.h>
using namespace std;

int main(){
	const int i = 10;
	
	int j = 12;
	const int& k = j;
	
	j++;
	k++;//Will give an error as the path to j using k is now constant and cannot be modified.
	cout<<j<<endl;
	
	int const j2 = 14;
	int const &k2 = j2;
	
	int const j3 = 15;
	int &k3 = j3;//Wrong as j3 is only read-only
}	
