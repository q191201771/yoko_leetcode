// Write an algorithm to determine if a number is "happy".
//
// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by
// the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it
// loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
// Example:
//
// Input: 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    bool isHappy(int n) {
      if (n <= 0) { return false; }

      while (1) {
        int res = 0;
        while (n > 0) {
          int l = n % 10;
          n /= 10;
          res += l*l;
        }
        if (res == 1) { return true; }
        if (res == 0) { return false; }

        n = res;
      }

    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  bool res = s.isHappy(19);
  std::cout << "res:" << res << std::endl;

  return 0;
}
#endif
