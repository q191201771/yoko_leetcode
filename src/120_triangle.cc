// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if (triangle.empty()) { return 0; }

      for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
          if (j == 0) { triangle[i][0] += triangle[i-1][0]; }
          else if (j == i) { triangle[i][j] += triangle[i-1][j-1]; }
          else { triangle[i][j] += triangle[i-1][j-1] < triangle[i-1][j] ? triangle[i-1][j-1] : triangle[i-1][j]; }
        }
      }
      int m = 0x7FFFFFFF;
      vector<int> &b = triangle.back();
      for (int i = 0; i < b.size(); i++) {
        if (b[i] < m) { m = b[i]; }
      }
      return m;
    }
};
#ifdef YOKO_DEBUG
int main() {
  vector<vector<int> > t({{2}, {3,4}, {6,5,7}, {4,1,8,3}});
  Solution().minimumTotal(t);
  std::cout << chef::stringify_stl(t) << std::endl;
  return 0;
}
#endif
