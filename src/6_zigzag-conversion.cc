// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string s, int numRows);
// Example 1:
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I



class Solution {
  public:
    string convert(string s, int numRows) {
      if (s.empty() || numRows == 0 || numRows == 1) { return s; }

      std::vector<std::string> columns;
      int column = 0;
      std:size_t i = 0;
      for (; ; ) {
        std::string val;
        if (column % (numRows - 1) == 0) {
          if (s.length() - i > numRows) {
            val = s.substr(i, numRows);
            columns.push_back(val);
            i += numRows;
          } else {
            val = s.substr(i);
            columns.push_back(val);
            break;
          }
        } else {
          int index = numRows - 1 - (column % (numRows - 1));
          val = std::string(numRows, '*');
          val[index] = s[i++];
          columns.push_back(val);
          if (i == s.length()) {
            break;
          }
        }
        column++;
      }

      std::string ret;
      for (int row = 0; row < numRows; row++) {
        for (std::size_t i = 0; i < columns.size(); i++) {
          if (columns[i].size() > row && columns[i][row] != '*') {
            ret += columns[i][row];
          }
        }
      }
      return ret;

    }
};
