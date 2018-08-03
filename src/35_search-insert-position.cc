// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it
// would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Example 1:
//
// Input: [1,3,5,6], 5
// Output: 2
// Example 2:
//
// Input: [1,3,5,6], 2
// Output: 1
// Example 3:
//
// Input: [1,3,5,6], 7
// Output: 4
// Example 4:
//
// Input: [1,3,5,6], 0
// Output: 0



class Solution {
private:
  int help(vector<int> &nums, int target, int l, int r) {
    if (l > r) { return r+1; }

    int m = (l+r) / 2;
    if (nums[m] == target) { return m; }
    else if (nums[m] < target) { return help(nums, target, m+1, r); }
    else { return help(nums, target, l, m-1); }
  }
public:
    int searchInsert(vector<int>& nums, int target) {
      if (nums.empty()) { return -1; }

      return help(nums, target, 0, nums.size()-1);
    }
};
