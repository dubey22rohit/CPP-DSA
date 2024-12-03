#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/word-search/

bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
  if (i == word.size()) {
    return true;
  }
  if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0 ||
      board[r][c] == '#' || board[r][c] != word[i]) {
    return false;
  }

  board[r][c] = '#';
  bool ans =
      dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) ||
      dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
  board[r][c] = word[i];
  return ans;
}

bool exists(vector<vector<char>>& board, string word) {
  if (board.size() == 0) {
    return false;
  }
  if (word.length() == 0) {
    return true;
  }

  int ROWS = board.size();
  int COLS = board[0].size();

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (dfs(board, word, r, c, 0)) {
        return true;
      }
    }
  }
  return false;
}

int main() { return 0; }