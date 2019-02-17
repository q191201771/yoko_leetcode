// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  bool isPalindrome(string &s, int b, int e) {
    for (; b <= e; b++,e--) {
      if (s[b] != s[e]) { return false; }
    }
    return true;
  }
  void help(string &s, int index, vector<string> &one, int &ret) {
    if (index == s.length()) { if (one.size()-1 < ret) { ret = one.size()-1; } }

    for (int i = index; i < s.length(); i++) {
      if (isPalindrome(s, index, i)) {
        one.push_back(s.substr(index, i-index+1));
        if (one.size()-1 < ret) { help(s, i+1, one, ret); }

        one.pop_back();
      }
    }
  }
public:
    int minCut(string s) {
      vector<string> one;
      int ret = 0x7FFFFFFF;
      help(s, 0, one, ret);
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  int ret = s.minCut("fff");
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
