// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique
// combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]



class Solution {
private:
  void help(vector<int> &candidates, int target, int i, int sum, vector<int> &one, vector<vector<int>> &ret) {
    if (sum == target) {
      ret.push_back(one);
      return;
    }

    for (std::size_t j = i; j < candidates.size(); j++) {
      if (candidates[j]+sum <= target) {
        one.push_back(candidates[j]);
        help(candidates, target, j, candidates[j]+sum, one, ret);
        one.pop_back();
      }
    }
  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ret;
      if (candidates.empty()) { return ret; }

      vector<int> one;
      help(candidates, target, 0, 0, one, ret);

      return ret;
    }
};
