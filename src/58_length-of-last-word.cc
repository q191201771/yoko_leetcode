// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// Example:
//
// Input: "Hello World"
// Output: 5



// "a " -> 1
class Solution {
public:
    int lengthOfLastWord(string s) {
      if (s.empty()) { return 0; }

      int i = s.size()-1;
      int e = -1;
      for (; i >= 0; i--) {
        if (s[i] == ' ') {
          if (e != -1) {
            break;
          }
          continue;
        } else {
          if (e == -1) {
            e = i;
          }
        }
      }

      return e-i;
    }
};
