// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:
//
// Input: dividend = 7, divisor = -3
// Output: -2
// Note:
//
// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif

// -2147483648, -1
// -2147483648, 1
// 7, -3
// 10,  3
// -1,  1
/// TODO try solve with shift op
class Solution {
public:
    int divide(int dividend, int divisor) {
      bool positive = !((dividend < 0) ^ (divisor < 0));
      unsigned int dd, ds;
      dd = dividend < 0 ? -dividend : dividend;
      ds = divisor < 0 ? -divisor : divisor;


      if (ds == 1) {
        if (positive && dd > 0x7FFFFFFF) {
          return 0x7FFFFFFF;
        }
        return positive ? dd : -dd;
      }

      int ret = 0;
      for (; ds <= dd; ) {
        ret++;
        dd -= ds;
      }
      return positive ? ret : -ret;
    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  s.divide(-2147483648, -1);
  return 0;
}
#endif
