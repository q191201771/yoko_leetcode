// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
//
// Input: 4
// Output: 2
// Example 2:
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since
//              the decimal part is truncated, 2 is returned.



// 2147395599
class Solution {
public:
    int mySqrt(int x) {
      if (x <= 1) { return x; }

      int l = 0;
      int r = x/2 + 1;
      long long m;
      while (l <= r) {
        m = ((long long)l+r) / 2;
        long long res = m * m;
        if (res == x) { return m; }
        else if (res < x) { l = m+1; }
        else { r = m-1; }
      }
      return r;
    }
};
