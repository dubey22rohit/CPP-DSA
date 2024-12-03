#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/n-queens/description/
bool isSafe(int r, int c, vector<string> board) {
  // Same column
  for (int i = r - 1; i >= 0; i--) {
    if (board[i][c] == 'Q') {
      return false;
    }
  }

  // upper left diagonal
  for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  // upper right diagonal
  for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  return true;
}

void backtrack(int r, vector<string>& board, vector<vector<string>>& result) {
  if (r == board.size()) {
    result.push_back(board);
    return;
  }

  for (int c = 0; c < board.size(); c++) {
    if (isSafe(r, c, board)) {
      board[r][c] = 'Q';
      backtrack(r + 1, board, result);
      board[r][c] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> result;
  vector<string> board(n, string(n, '.'));
  backtrack(0, board, result);
  return result;
}

int main() { return 0; }