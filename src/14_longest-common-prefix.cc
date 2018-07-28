// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:
//
// All given inputs are in lowercase letters a-z.



// ["flower","flow","flight"]
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) { return std::string(); }

      std::size_t min_len = strs[0].length();
      for (std::size_t i = 1; i < strs.size(); i++) {
        min_len = strs[i].length() < min_len ? strs[i].length() : min_len;
      }

      std::size_t i = 0;
      for (; i < min_len; i++) {
        char ch = strs[0][i];
        for (std::size_t j = 1; j < strs.size(); j++) {
          if (ch != strs[j][i]) {
            goto END;
          }
        }
      }

END:
      return strs[0].substr(0, i);

    }
};
