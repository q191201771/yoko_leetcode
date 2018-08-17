Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum
of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.



class Solution {
private: int __min(int x, int y) { return x < y ? x : y; }
public:
    int minPathSum(vector<vector<int>>& grid) {
      int row = grid.size();
      int column = grid[0].size();
      if (row == 0 || column == 0) { return -1; }

      vector<vector<int> > score = grid;
      for (int i = 1; i < column; i++) {
        score[0][i] = score[0][i-1] + grid[0][i];
      }
      for (int i = 1; i < row; i++) {
        score[i][0] = score[i-1][0] + grid[i][0];
      }

      for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
          score[i][j] = __min(score[i-1][j], score[i][j-1]) + grid[i][j];
        }
      }
      return score[row-1][column-1];
    }
};
