// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif

// "()(()"
// ")()())"
// "(()"
class Solution {
public:
    int longestValidParentheses(string s) {
      std::stack<int> ss;
      for (std::size_t i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
          ss.push(i);
        } else { // ')'
          if (ss.empty()) {
            ss.push(i);
          } else {
            if (s[ss.top()] == '(') {
              ss.pop();
            } else {
              ss.push(i);
            }
          }
        }
      }

      if (ss.empty()) { return s.length(); }

      int m = 0;
      int r = s.length();
      while (!ss.empty()) {
        int l = ss.top();
        ss.pop();
        if (r - l - 1 > m) { m = r - l - 1; }

        r = l;
      }

      if (r > m) { m = r; }

      return m;
    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  s.longestValidParentheses("(()");
  return 0;
}
#endif
