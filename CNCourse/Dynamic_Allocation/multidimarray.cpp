#include<bits/stdc++.h>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	int** p = new int[m];
	for (int i = 0; i < m; i ++)
	{
		p[i] = new int[n];
		for (int j = 0; j < n; j += 1)
		{
			cin >> p[i][j]; 
		}
	}
	
	for (int i = 0; i < m; i += 1)
	{
		delete [] p[i];
	}
	
	delete [] p;
}
