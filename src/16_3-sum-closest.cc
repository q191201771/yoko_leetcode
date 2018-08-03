// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



// [-1,2,1,-4]  1
class Solution {
private:
  int diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
  }
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int ret;
      int min_diff = 0x7FFFFFFF;

      std::sort(nums.begin(), nums.end());

      for (std::size_t i = 0; i < nums.size()-2; i++) {
        std::size_t l = i+1;
        std::size_t r = nums.size()-1;

        while (l < r) {
          int sum = nums[i] + nums[l] + nums[r];
          if (diff(sum, target) < min_diff) { min_diff = diff(sum, target); ret = sum; }

          if (sum == target) { return target; }
          else if (sum < target) { l++; }
          else if (sum > target) { r--; }
        }
      }
      return ret;

    }
};
