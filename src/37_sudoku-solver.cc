// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.
//
//
// A sudoku puzzle...
//
//
// ...and its solution numbers marked in red.
//
// Note:
//
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.



class Solution {
private:
  bool is_valid(vector<vector<char>> &board, int row, int column, char val) {
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == val) { return false; }

      if (board[i][column] == val) { return false; }
    }

    int subi = (row/3)*3;
    int subj = (column/3)*3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[subi+i][subj+j] == val) { return false; }
      }
    }

    return true;
  }

  bool help(vector<vector<char> > &board, int index) {
    if (index == 81) { return true; }

    int i = index / 9;
    int j = index % 9;

    if (board[i][j] != '.') {
      return help(board, index+1);
    } else {
      for (char k = '1'; k <= '9'; k++) {
        if (is_valid(board, i, j, k)) {
          board[i][j] = k;
          if (help(board, index+1)) {
            return true;
          }
          board[i][j] = '.';
        }
      }
    }
    return false;
  }
public:
    void solveSudoku(vector<vector<char>>& board) {
      help(board, 0);
    }
};
