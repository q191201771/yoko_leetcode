// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and
// is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.
//
// Example 1:
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
// Example 2:
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3



class Solution {
  private:
    void help(vector<vector<char> > &grid, int i, int j) {
      if (i < 0 || i == grid.size() ||
          j < 0 || j == grid[0].size() ||
          grid[i][j] != '1'
      ) {
        return;
      }
      grid[i][j] = '2';
      help(grid, i+1, j);
      help(grid, i-1, j);
      help(grid, i, j+1);
      help(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
      int result = 0;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          if (gird[i][j] == '1') {
            result++;
            help(grid, i, j);
          }
        }
      }
      return result;
    }
};
