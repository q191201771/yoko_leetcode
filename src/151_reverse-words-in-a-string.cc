// Given an input string, reverse the string word by word.
//
// Example:
//
// Input: "the sky is blue",
// Output: "blue is sky the".
// Note:
//
// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or
// trailing spaces.
// You need to reduce multiple spaces between two words to a single space in the reversed string.
// Follow up: For C programmers, try to solve it in-place in O(1) space.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  void __replace(string &s, int f, int t, int len) {
    for (int i = 0; i < len; i++) {
      s[t+i] = s[f+i];
    }
  }
  void __copy(string &s, int t, int len, const char *f) {
    for (int i = 0; i < len; i++) {
      s[t+i] = *(f+i);
    }
  }
public:
    void reverseWords(string &s) {
      if (s.empty()) { return; }

      // trim left space
      int begin = 0;
      for (; begin < s.length(); begin++) {
        if (s[begin] != ' ') { break; }
      }
      if (begin == s.length()) {
        s = "";
        return;
      }
      // trim right space
      int end = s.length() - 1;
      for (; end >= 0; end--) {
        if (s[end] != ' ') { break; }
      }
      if (end == -1) {
        s = "";
        return;
      }

      // trim extra mid space
      int j = begin;
      for (int i = begin; i <= end;) {
        if (s[i] != ' ') {
          if (j != i) { s[j] = s[i]; }

          i++; j++;
        } else {
          for (; s[i] == ' '; i++);

          s[j++] = ' ';
        }
      }
      end = j-1;

      int i = begin;
      int ie = end;
      for (; i <= ie;) {
        if (s[i] == ' ') {
          // Am `item` count as extra space?
          string item = s.substr(begin, i-begin);

          __replace(s, i+1, begin, ie-i);

          s[ie-i+begin] = ' ';
          __copy(s, ie-i+begin+1, i-begin, item.c_str());

          ie = ie - (i-begin) - 1;
          i = begin;
        } else {
          i++;
        }
      }
      s = s.substr(begin, end-begin+1);

    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  string str = "the sky is blue";
  //string str = " 1";
  //string str = "1 ";
  std::cout << "origin:\'" << str << "\'" << std::endl;
  s.reverseWords(str);
  std::cout << "ret:\'" << str << "\'" << std::endl;
  return 0;
}
#endif
