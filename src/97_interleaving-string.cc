// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      int sl1 = s1.length();
      int sl2 = s2.length();
      int sl3 = s3.length();
      if (sl1+sl2 != sl3) { return false; }

      std::vector<int> one(sl1+1, 0);
      std::vector<std::vector<int> > v(sl2+1, one);

      v[0][0] = 1;
      for (int i = 1; i < sl1+1; i++) {
        if (s1[i-1] != s3[i-1]) { break; }

        v[0][i] = 1;
      }

      for (int i = 1; i < sl2+1; i++) {
        if (s2[i-1] != s3[i-1]) { break; }

        v[i][0] = 1;
      }

      for (int row = 1; row < sl2+1; row++) {
        for (int column = 1; column < sl1+1; column++) {
          if (v[row-1][column] == 1 && s2[row-1] == s3[row+column-1]) { v[row][column] = 1; }
          else if (v[row][column-1] == 1 && s1[column-1] == s3[row+column-1]) { v[row][column] = 1; }
        }
      }
      //std::cout << chef::stringify_stl(v, chef::STRINGIFY_STL_STYLE_ONE_BEAUTY) << std::endl;
      return v[sl2][sl1];
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  std::cout << s.isInterleave("a", "", "a") << std::endl;
  std::cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
  std::cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << std::endl;
  return 0;
}
#endif
