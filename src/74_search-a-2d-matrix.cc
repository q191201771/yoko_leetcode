// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.empty() || matrix[0].empty()) { return false; }

      int row = matrix.size();
      int column = matrix[0].size();
      if (target < matrix[0][0] || target > matrix[row-1][column-1]) { return false; }

      int ul = 0;
      int dl = row-1;
      while (ul <= dl) {
        int m = (ul + dl) / 2;
        if (matrix[m][0] == target) { return true; }
        else if (matrix[m][0] < target) { ul=m+1; }
        else { dl=m-1; }
      }
      int l = 0;
      int r = column-1;
      while (l <= r) {
        int m = (l + r) / 2;
        if (matrix[dl][m] == target) { return true; }
        else if (matrix[dl][m] < target) { l=m+1; }
        else { r=m-1; }
      }
      return false;
    }
};
