// Implement pow(x, n), which calculates x raised to the power n (xn).
//
// Example 1:
//
// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:
//
// Input: 2.10000, 3
// Output: 9.26100
// Example 3:
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
// Note:
//
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]



class Solution {
private:
  int __abs(int x) { return x >=0 ? x : -x; }
public:
    double myPow(double x, int n) {
      if (n == 0) { return 1; }

      if (n == 1) { return x; }

      if (x >= -0.0001f && x <= 0.0001f) { return 0; }

      if (x == 1.0f) { return 1.0f; }

      if (x == -1.0f) { return (n/2 == 0) ? 1.0f : -1.0f; }

      double ret = x;
      int absn = __abs(n);
      for (int i = 0; i < absn-1; i++) {
        ret *= x;
      }
      if (n < 0) { ret = 1/ret; }

      return ret;
    }
};
