// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in
// candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]


// [10,1,2,7,6,1,5]  8
// [2,5,2,1,2]  5
class Solution {
private:
  void help(vector<int> &candidates, int target, int bpos, int sum, vector<int> &one, vector<vector<int> > &ret) {
    if (sum == target) {
      ret.push_back(one);
      return;
    }

    for (std::size_t i = bpos; i< candidates.size(); i++) {
      if (i > 0 && candidates[i] == candidates[i-1] && i > bpos) { continue; }

      if (sum + candidates[i] > target) { break; }

      one.push_back(candidates[i]);
      help(candidates, target, i+1, sum+candidates[i], one, ret);
      one.pop_back();
    }

  }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int> > ret;
      if (candidates.empty()) { return ret; }

      sort(candidates.begin(), candidates.end());
      vector<int> one;
      help(candidates, target, 0, 0, one, ret);
      return ret;
    }
};
