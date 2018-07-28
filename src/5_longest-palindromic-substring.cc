// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:
//
// Input: "cbbd"
// Output: "bb"



#ifdef YOKO_DEBUG
#include <string>
using namespace std;
#endif

class Solution {
public:
    string longestPalindrome(string s) {
      if (s.empty()) { return s; }

      int max_len = 1;
      int bpos = 0;
      for (std::size_t i = 0; i < s.length(); i++) {
        int l = i-1;
        int r = i+1;
        while (r < s.length() && s[i] == s[r]) { r++; }

        while (l >= 0 && r < s.length() && s[l] == s[r]) { l--; r++; }

        if ((r - l - 1) > max_len) {
          max_len = r - l - 1;
          bpos = l + 1;
        }
      }

      return s.substr(bpos, max_len);

    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  //s.longestPalindrome("babad");
  //s.longestPalindrome("cbbd");
  s.longestPalindrome("bb");

  return 0;
}
#endif
