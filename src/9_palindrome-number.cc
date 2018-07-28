// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
// Input: 121
// Output: true
// Example 2:
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:
//
// Coud you solve it without converting the integer to a string?



#ifdef YOKO_DEBUG
#include <iostream>
#endif

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) { return false; }

      int x_keeper = x;
      int y = 0;
      for (; ; ) {
        y = y * 10 + (x % 10);
        x /= 10;
        if (x == 0) {
          break;
        }
      }

      return x_keeper == y;

    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  s.isPalindrome(121);
  return 0;
}
#endif
