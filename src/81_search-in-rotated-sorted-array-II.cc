// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
// Follow up:
//
// This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// Would this affect the run-time complexity? How and why?



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  bool help(vector<int> &nums, int l, int r, int target) {
    if (l > r) { return false; }

    int m = (l+r) / 2;
    bool lr = nums[l] >= nums[m];
    bool rr = nums[m] >= nums[r];

    if (nums[m] == target) {
      return true;
    } else if (nums[m] < target) {
      if (help(nums, m+1, r, target)) { return true; }

      if (lr) { return help(nums, l, m-1, target); }
    } else { // nums[m] > target
      if (help(nums, l, m-1, target)) { return true; }

      if (rr) { return help(nums, m+1, r, target); }
    }

    return false;
  }
public:
    bool search(vector<int>& nums, int target) {
      if (nums.empty()) { return false; }

      return help(nums, 0, nums.size()-1, target);
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  bool res;
  //vector<int> vec({2,5,6,0,0,1,2});
  //res = s.search(vec, 3);
  //vector<int> vec({3,1});
  //res = s.search(vec, 1);
  vector<int> vec({1,3,1,1,1});
  res = s.search(vec, 3);
  printf("res:%d\n", res);
  return 0;
}
#endif
