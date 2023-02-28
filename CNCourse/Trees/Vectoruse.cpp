#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int> v;
    // vector<int> *vp = new vector<int>();//Dynamic
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    cout << "SIZE : " << v.size()<<endl;
    cout << v.at(2);
    // At is safer to use, won't return garbage
    v.pop_back();
    cout << "SIZE : " << v.size()<<endl;

}