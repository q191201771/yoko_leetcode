// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]



// []  0
// [1]  0
class Solution {
private:
  int help(vector<int> &nums, int target, int l, int r) {
    if (l > r) { return -1; }

    int m = (l + r) / 2;
    if (nums[m] == target) { return m; }
    else if (nums[m] < target) { return help(nums, target, m+1, r); }
    else { return help(nums, target, l, m-1); }
  }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      std::vector<int> ret({-1, -1});
      if (nums.empty()) { return ret; }

      int index = help(nums, target, 0, nums.size()-1);
      if (index == -1) { return ret; }

      int i = index-1;
      for (; i >= 0; i--) {
        if (nums[i] != target) { break; }
      }
      ret[0] = i+1;
      i = index+1;
      for (; i <= nums.size()-1; i++) {
        if (nums[i] != target) { break; }
      }
      ret[1] = i-1;
      return ret;
    }
};
