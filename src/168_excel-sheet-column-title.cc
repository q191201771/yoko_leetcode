// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB
//     ...
// Example 1:
//
// Input: 1
// Output: "A"
// Example 2:
//
// Input: 28
// Output: "AB"
// Example 3:
//
// Input: 701
// Output: "ZY"



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    string convertToTitle(int n) {
      string ret;
      while (n > 26) {
        int a = n % 26;
        if (a != 0) {
          ret.insert(ret.begin(), 'A'+a-1);
        } else {
          ret.insert(ret.begin(), 'Z');
          n -= 26;
        }
        n /= 26;
      }
      cout << n << endl;
      ret.insert(ret.begin(), 'A'+n-1);
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  string ret;
  ret = s.convertToTitle(1);   assert(ret == "A");
  ret = s.convertToTitle(26);  assert(ret == "Z");
  ret = s.convertToTitle(27);  assert(ret == "AA");
  ret = s.convertToTitle(28);  assert(ret == "AB");
  ret = s.convertToTitle(701); assert(ret == "ZY");
  ret = s.convertToTitle(52);  assert(ret == "AZ");
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
