#include <iostream>
#include <vector>
using namespace std;

// Squaring a Sorted Array (easy)
static vector<int> makeSquares(const vector<int>& arr){
    int n = arr.size();
    vector<int> squares(n);
    int i = 0, j = n - 1 , k = n - 1;
    while(i <= j){
        if(abs(arr[i]) > abs(arr[j])){
            squares[k--] = arr[i] * arr[i];
            i++;
        }else{
            squares[k--] = arr[j] * arr[j];
            j--;
        }
    }
    return squares;
}

int main(){
    vector<int> squares = makeSquares({-2,-1, 0, 2, 3});
    for(auto s: squares){
        cout << s << " ";
    }
    return 0;
}