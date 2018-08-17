Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]



class Solution {
  private:
    void help(int index, vector<int> &nums, vector<vector<int> > &ret, vector<int> &one) {
      if (index == nums.size()) {
        return;
      }

      for (int i = index; i < nums.size(); i++) {
        one.push_back(nums[i]);
        ret.push_back(one);
        help(i+1, nums, ret, one);
        one.pop_back();
      }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int> > ret;
      vector<int> one;
      ret.push_back(one);
      help(0, nums, ret, one);
      return ret;
    }
};
