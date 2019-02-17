// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:
//
// Input: "race a car"
// Output: false



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    bool isPalindrome(string s) {
      string ss;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') { ss += s[i] - 'A' + 'a'; }
        else if (s[i] >= 'a' && s[i] <= 'z') { ss += s[i]; }
        else if (s[i] >= '0' && s[i] <= '9') { ss += s[i]; }
        else { continue; }
      }

      if (ss.empty() || ss.length() == 1) { return true; }

      int i = 0;
      int j = ss.length()-1;

      for (; i < j; ) {
        if (ss[i++] != ss[j--]) { return false; }
      }
      return true;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  std::cout << s.isPalindrome("0P") << std::endl; // 0
  std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << std::endl; // 1
  std::cout << s.isPalindrome("a.") << std::endl; // 1
  return 0;
}
#endif
