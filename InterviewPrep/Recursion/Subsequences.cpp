#include <iostream>
#include <vector>
using namespace std;

int subsequences(string input, vector<string> &output) {
  if (input.size() == 0) {
    output[0] = "";
    return 1;
  }

  string smallString = input.substr(1);
  int smallOutputSize = subsequences(smallString, output);
  for (int i = 0; i < smallOutputSize; i++) {
    output[i + smallOutputSize] = input[0] + output[i];
  }

  return 2 * smallOutputSize;
}

void dfs(string input, string curr, int index, vector<string> &output) {
  if (find(output.begin(), output.end(), curr) == output.end()) {
    output.push_back(curr);
  }
  for (int i = index; i < input.size(); i++) {
    curr.push_back(input[i]);
    dfs(input, curr, i + 1, output);
    curr.pop_back();
  }
}

vector<string> subsequences2(string input) {
  vector<string> output;
  string curr = "";
  dfs(input, curr, 0, output);
  return output;
}

int main() {
  string input;
  getline(cin, input);

  vector<string> output(pow(2, input.size()));

  int ans = subsequences(input, output);

  for (int i = 0; i < ans; i++) {
    cout << output[i] << ", ";
  }

  cout << "\nDFS:\n";
  vector<string> op2 = subsequences2(input);
  cout << op2.size() << endl;

  for (auto s : op2) {
    cout << s << ", ";
  }

  return 0;
}