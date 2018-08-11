// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
//
// Example:
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]



class Solution {
private:
  bool check_diagonal(vector<string> &one, int n, int i, int j) {
    for (int ii=i,jj=j; ii > 0 && jj > 0; ) {
      --ii;--jj;
      if (one[ii][jj] == 'Q') { return false; }
    }
    for (int ii=i,jj=j; ii < (n-1) && jj < (n-1); ) {
      ++ii;++jj;
      if (one[ii][jj] == 'Q') { return false; }
    }
    for (int ii=i,jj=j; ii > 0 && jj < (n-1); ) {
      --ii;++jj;
      if (one[ii][jj] == 'Q') { return false; }
    }
    for (int ii=i,jj=j; ii < (n-1) && jj > 0; ) {
      ++ii;--jj;
      if (one[ii][jj] == 'Q') { return false; }
    }
    return true;
  }

  void help(int n, int index, int &ret, vector<string> &one) {
    if (index == n*n) {
      ret++;
      return;
    }

    int i = index / n;
    int j = index % n;

    int rcount = 0;
    int ccount = 0;
    for (int k = 0; k < n; k++) {
      if (one[i][k] == 'Q') { rcount++; }

      if (one[k][j] == 'Q') { ccount++; }
    }

    if (!((i == n-1 && ccount == 0) || (j == n-1 && rcount == 0))) {
      help(n, index+1, ret, one);
    }

    if (rcount == 0 && ccount == 0 && check_diagonal(one, n, i, j)) {
      one[i][j] = 'Q';
      help(n, index+1, ret, one);
      one[i][j] = '.';
    }
  }
public:
    int totalNQueens(int n) {
      int ret = 0;
      vector<string> one;
      for (int i = 0; i < n; i++) {
        one.push_back(std::string(n, '.'));
      }

      help(n, 0, ret, one);
      return ret;
    }
};

