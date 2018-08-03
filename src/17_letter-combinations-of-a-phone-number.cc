Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.



// "23" ["ad","ae","af","abd","abe","abf","abcd","abce","abcf"]
class Solution {
  private:
    void helper(const std::string &digits, std::size_t i, const std::vector<std::string> &mapping,
                std::string &one, std::vector<std::string> &ret) {
      if (i == digits.size()) {
        ret.push_back(one);
        return;
      }

      std::string str = mapping[digits[i]-'0'];
      for (std::size_t j = 0; j < str.length(); j++) {
        one.push_back(str[j]);
        helper(digits, i+1, mapping, one, ret);
        one.pop_back();
      }
    }

  public:
      vector<string> letterCombinations(string digits) {
        std::vector<std::string> ret;

        if (digits.empty()) { return ret; }

        std::vector<std::string> mapping(10, "");
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        std::string one;
        helper(digits, 0, mapping, one, ret);

        return ret;

      }
};
