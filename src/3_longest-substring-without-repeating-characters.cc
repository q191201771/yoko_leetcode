// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.



#ifdef YOKO_DEBUG
#include <string>
using namespace std;
#endif

// "c" -> 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ret = 0;
      int mapping[256];
      for (int i = 0; i < 256; i++) { mapping[i] = -1; }

      int bpos = 0;
      for (std::size_t i = 0; i < s.length(); i++) {
        int key = (int)s[i];
        if (mapping[key] == -1 || mapping[key] < bpos) {
          if (i - bpos + 1 > ret) {
            ret = i - bpos + 1;
          }
        } else {
          if (i - mapping[key] > ret) {
            ret = i - mapping[key];
          }
          bpos = mapping[key] + 1;
        }
        mapping[key] = i;
      }
      return ret;

    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  s.lengthOfLongestSubstring("abcabcbb");
  return 0;
}
#endif
