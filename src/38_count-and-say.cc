// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
// Example 1:
//
// Input: 1
// Output: "1"
// Example 2:
//
// Input: 4
// Output: "1211"



class Solution {
public:
    string countAndSay(int n) {
      if (n == 1) { return "1"; }
      if (n == 2) { return "11"; }

      std::string prev_res = countAndSay(n-1);
      std::string ret;
      int count = 1;
      char key = prev_res[0];
      for (std::size_t i = 1; i < prev_res.length(); i++) {
        if (key == prev_res[i]) {
          count++;
        } else {
          ret += ('0'+count);
          ret += key;
          count = 1;
          key = prev_res[i];
        }
      }
      ret += ('0'+count);
      ret += key;

      return ret;
    }
};
