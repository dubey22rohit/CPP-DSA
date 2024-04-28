#include <iostream>
#include <vector>
using namespace std;

// Words Concatenation (hard)
static vector<int> findWordConcatenation(const string &str, const vector<string> &words){
    // TODO
}

int main(){
    string str = "catfoxcat";
    vector<string> words = ["cat", "fox"];
    vector<int> ans = findWordConcatenation(str, words);
    for(int a: ans){
        cout << a << " ";
    }
    return 0;
}