// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
// Example 1:
//
// Input: [5,7]
// Output: 4
// Example 2:
//
// Input: [0,1]
// Output: 0



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      if (m == n) { return m; }

      int ret = 0x7FFFFFFF;
      for (int i = m; i <= n; i++) {
        ret &= i;
        //std::cout << "i:" << i << ",ret:" << ret << std::endl;
        if (i == 0x7FFFFFFF) { break; }
        if (ret == 0) { return ret; }
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  int ret;
  //ret = s.rangeBitwiseAnd(2147483646, 2147483647);
  //ret = s.rangeBitwiseAnd(0, 0);
  ret = s.rangeBitwiseAnd(2147483647, 2147483647);
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
