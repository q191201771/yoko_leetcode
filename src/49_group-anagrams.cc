// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
//
// All inputs will be in lowercase.
// The order of your output does not matter.



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string> > ret;
      map<vector<int>, vector<string> > m;

      for (int i = 0; i < strs.size(); i++) {
        vector<int> v(26, 0);
        for (int j = 0; j < strs[i].length(); j++) {
          v[strs[i][j]-'a']++;
        }
        m[v].emplace_back(strs[i]);
      }
      for (auto &item : m) {
        ret.emplace_back(item.second);
      }

      return ret;
    }
};
