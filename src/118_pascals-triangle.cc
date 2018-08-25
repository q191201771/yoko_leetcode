// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int> > ret;
      for (int i = 0; i < numRows; i++) {
        vector<int> one;
        for (int j = 0; j < i+1; j++) {
          if (j == 0 || j == i) {
            one.push_back(1);
          } else {
            one.push_back(ret[i-1][j-1]+ret[i-1][j]);
          }
        }
        ret.push_back(one);
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  std::cout << chef::stringify_stl(Solution().generate(5)) << std::endl;
  return 0;
}
#endif
