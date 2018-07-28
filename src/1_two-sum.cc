// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::vector<int> res;
      std::unordered_map<int, int> m;
      for (std::size_t i = 0; i < nums.size(); i++) {
        auto iter = m.find(nums[i]);
        if (iter == m.end()) {
          m[target-nums[i]] = i;
        } else {
          res.push_back(iter->second);
          res.push_back(i);
          return res;
        }
      }

    }
};
