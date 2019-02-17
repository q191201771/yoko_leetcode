// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]



class Solution {
private:
  bool isPalindrome(string &s, int b, int e) {
    for (; b <= e; b++,e--) {
      if (s[b] != s[e]) { return false; }
    }
    return true;
  }
  void help(string &s, int index, vector<string> &one, vector<vector<string> > &ret) {
    if (index == s.length()) { ret.push_back(one); }

    for (int i = index; i < s.length(); i++) {
      if (isPalindrome(s, index, i)) {
        one.push_back(s.substr(index, i-index+1));
        help(s, i+1, one, ret);
        one.pop_back();
      }
  }
public:
    vector<vector<string>> partition(string s) {
      vector<string> one;
      vector<vector<string> > ret;
      help(s, 0, one, ret);
      return ret;
    }
};
