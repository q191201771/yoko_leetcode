// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// The array may contain duplicates.
//
// Example 1:
//
// Input: [1,3,5]
// Output: 1
// Example 2:
//
// Input: [2,2,2,0,1]
// Output: 0
// Note:
//
// This is a follow up problem to Find Minimum in Rotated Sorted Array.
// Would allow duplicates affect the run-time complexity? How and why?



class Solution {
private:
  int __min(int a, int b) { return a < b ? a : b; }

  void __findMind(vector<int> &nums, int l, int r, int &ret) {
    if (l > r) { return; }

    if (l == r) { ret = __min(nums[l], ret); return; }

    if (nums[l] < nums[r]) {
      ret = __min(nums[l], ret);
    } else {
      int mid = (l + r) / 2;
      __findMind(nums, l, mid, ret);
      __findMind(nums, mid+1, r, ret);
    }
  }
public:
    int findMin(vector<int>& nums) {
      if (nums.empty()) { return 0; }

      int ret = 0x7FFFFFFF;
      int l = 0;
      int r = nums.size()-1;
      __findMind(nums, l, r, ret);
      return ret;
    }
};
