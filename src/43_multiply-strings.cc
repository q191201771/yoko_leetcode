// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:
//
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    string multiply(string num1, string num2) {
      string ret(num1.size()+num2.size(), '0');

      for (int i = num1.size()-1; i >= 0; i--) {
        for (int j = num2.size()-1; j >= 0; j--) {
          int tmp = (num1[i] - '0') * (num2[j] - '0');
          ret[i+j+1] += tmp % 10;
          if (ret[i+j+1] >= ('0'+10)) {
            ret[i+j+1] -= 10;
            ret[i+j]++;
          }
          ret[i+j] += tmp / 10;
          if (ret[i+j] >= ('0'+10)) {
            ret[i+j] -= 10;
            ret[i+j-1]++;
          }
        }
      }

      std::size_t pos = ret.find_first_not_of('0');
      return pos == std::string::npos ? "0" : ret.substr(pos);
    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  std::cout << s.multiply("96", "313") << std::endl;
  return 0;
}
#endif
