#include <iostream>
using namespace std;

bool checkABHelper(char *input, int si) {
    if (input[si] == '\0') {
        return true;
    }
    if (input[si] != 'a') {
        return false;
    }

    if (input[si + 1] != '\0' && input[si + 2] != '\0') {
        if (input[si + 1] == 'b' && input[si + 2] == 'b') {
            return checkABHelper(input, si + 3);
        }
    }
    return checkABHelper(input, si + 1);
}

bool checkAB(char input[]) {
    bool ans = checkABHelper(input, 0);
    return ans;
}

// My solution:
//  bool checkAB(string s) {
//      if (s.empty()) {
//          return true;
//      }
//      int skip = 0;
//      if (s[0] == 'a') {
//          if (s[1] == 'a' || (s[1] == 'b' && s[2] == 'b')) {
//              if (s[1] == 'b' && s[2] == 'b') {
//                  skip = 3;
//              } else {
//                  skip = 2;
//              }
//              return checkAB(s.substr(skip)) && true;
//          }
//      } else if (s[0] == 'b' && s[1] == 'b') {
//          if (s[2] == 'a') {
//              skip = 3;
//              return checkAB(s.substr(skip)) && true;
//          }
//      }
//      return false;
//  }

int main() {
    int n;
    cin >> n;
    char *input = new char[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    bool ans = checkAB(input);
    cout << ans;

    delete[] input;

    return 0;
}