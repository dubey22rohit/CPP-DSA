#include<iostream>
using namespace std;

int sumOfNN(int n){
    if(n == 0){
        return 0;
    }
    return sumOfNN(n - 1) + n;
}

int main(){
    int i;
    cin >> i;
    cout << sumOfNN(i);
}