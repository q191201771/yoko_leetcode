// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif

class Solution {
private:
  int help(vector<int> &nums, int target, int l, int r) {
    if (l > r) { return -1; }

    int m = (l + r) / 2;
    int ret = -1;
    if (nums[m] == target) {
      return m;
    } else if (nums[m] < target) {
      ret = help(nums, target, m+1, r);
      if (ret != -1) { return ret; }
      if (nums[l] > nums[m]) {
        ret = help(nums, target, l, m-1);
        if (ret != -1) { return ret; }
      }
    } else if (nums[m] > target) {
      ret = help(nums, target, l, m-1);
      if (ret != -1) { return ret; }
      if (nums[r] < nums[m]) {
        ret = help(nums, target, m+1, r);
        if (ret != -1) { return ret; }
      }
    }
    return ret;

  }
public:
    int search(vector<int>& nums, int target) {
      if (nums.empty()) { return -1; }

      return help(nums, target, 0, nums.size()-1);
    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  std::vector<int> v({4, 5, 6, 7, 0, 1, 2});
  int res = s.search(v, 0);
  std::cout << "search result:" << res << std::endl;
  return 0;
}
#endif
