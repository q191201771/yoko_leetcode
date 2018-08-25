// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
// TODO maybe dp?
class Solution {
private:
  void help(string &s, int i, int &count) {
    if (i == s.length()) { count++; return; }

    if (s[i] >= '1' && s[i] <= '9') {
      help(s, i+1, count);
    }
    if (i+1 < s.length() && ((s[i] == '1' && s[i+1] >= '0' && s[i+1] <= '9') || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6'))) {
      help(s, i+2, count);
    }
  }
public:
    int numDecodings(string s) {
      int count = 0;
      help(s, 0, count);
      return count;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  int ret;
  ret = s.numDecodings("12");
  //ret = s.numDecodings("226");
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
