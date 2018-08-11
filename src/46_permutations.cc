// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]



class Solution {
private:
  void help(vector<int> &nums, int index, vector<vector<int> > &ret, vector<int> &one, set<int> &s) {
    if (index == nums.size()) {
      ret.push_back(one);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (s.find(i) != s.end()) { continue; }

      s.insert(i);
      one.push_back(nums[i]);
      help(nums, index+1, ret, one, s);
      s.erase(i);
      one.pop_back();
    }
  }
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int> > ret;
      vector<int> one;
      set<int> s;
      help(nums, 0, ret, one, s);
      return ret;
    }
};
