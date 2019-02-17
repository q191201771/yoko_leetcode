// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
// Input: [3,4,5,1,2]
// Output: 1
// Example 2:
//
// Input: [4,5,6,7,0,1,2]
// Output: 0



class Solution {
private:
  int __min(int a, int b) { return a < b ? a : b; }

  void __findMind(vector<int> &nums, int l, int r, int &ret) {
    if (l > r) { return; }

    if (nums[l] <= nums[r]) {
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
