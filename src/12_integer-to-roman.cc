// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
//
// Example 1:
//
// Input: 3
// Output: "III"
// Example 2:
//
// Input: 4
// Output: "IV"
// Example 3:
//
// Input: 9
// Output: "IX"
// Example 4:
//
// Input: 58
// Output: "LVIII"
// Explanation: C = 100, L = 50, XXX = 30 and III = 3.
// Example 5:
//
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.



#ifdef YOKO_DEBUG
#include <string>
using namespace std;
#endif

#define TRANS(n, str) if (num >= n) { ret.append(str); num -= n; continue; }
class Solution {
public:
    string intToRoman(int num) {
      std::string ret;
      for (; num != 0; ) {
        TRANS(1000, "M");
        TRANS(900,  "CM");
        TRANS(500,  "D");
        TRANS(400,  "CD");
        TRANS(100,  "C");
        TRANS(90,   "XC");
        TRANS(50,   "L");
        TRANS(40,   "XL");
        TRANS(10,   "X");
        TRANS(9,    "IX");
        TRANS(5,    "V");
        TRANS(4,    "IV");
        TRANS(1,    "I");
      }
      return ret;

    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  s.intToRoman(3);
  return 0;
}
#endif
