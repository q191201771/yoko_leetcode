// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
//
// Input: a = "1010", b = "1011"
// Output: "10101"



class Solution {
public:
    string addBinary(string a, string b) {
      int al = a.length();
      int bl = b.length();
      bool plus = false;
      string ret;
      for (int index = 0; index < al || index < bl; index++) {
        int val = 0;
        if (index < al) { val += a[al-index-1]-'0'; }
        if (index < bl) { val += b[bl-index-1]-'0'; }
        if (plus) { val += 1; }

        if (val >= 2) {
          val -= 2;
          plus = true;
        } else {
          plus = false;
        }
        ret.insert(0, 1, '0'+val);
      }
      if (plus) { ret.insert(0, 1, '0'); }

      return ret;
    }
};
