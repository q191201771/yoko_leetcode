Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]



class Solution {
private:
  void help(const string &s, int i, int &count, string &one, vector<string> &ret) {
    int len = s.length();

    if (i == len) {
      return;
    }

    if (i < len) {
      if (s[i] > '0' && s[i] < '9') {
        count++;
      }
    }
  }
public:
    vector<string> restoreIpAddresses(string s) {
      string one;
      vector<string> ret;
      help(s, 0, 0, one, ret);
    }
};
