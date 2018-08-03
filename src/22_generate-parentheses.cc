// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]



class Solution {
private:
  void helper(int i, int n, int l, int r, std::string &one, std::vector<std::string> &ret) {
    if (i >= n*2) {
      ret.push_back(one);
      return;
    }

    if (l < n) {
      one += "(";
      helper(i+1, n, l+1, r, one, ret);
      one.pop_back();
    }

    if (r < l) {
      one += ")";
      helper(i+1, n, l, r+1, one, ret);
      one.pop_back();
    }
  }
public:
    vector<string> generateParenthesis(int n) {
      std::vector<std::string> ret;
      if (n <= 0) { return ret; }

      std::string one;
      helper(0, n, 0, 0, one, ret);
      return ret;

    }
};
