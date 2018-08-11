// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
//
// Input: [1,2,0]
// Output: 3
// Example 2:
//
// Input: [3,4,-1,1]
// Output: 2
// Example 3:
//
// Input: [7,8,9,11,12]
// Output: 1
//
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.


#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
// [3,4,-1,1]
// [1,2,0]
class Solution {
private:
  void help(vector<int> &nums, int i) {
    if (nums[i] <= 0 || nums[i] > nums.size() || nums[i]-1 == i || nums[nums[i]-1] == nums[i]) { return; }

    int tmp = nums[nums[i]-1];
    nums[nums[i]-1] = nums[i];
    nums[i] = tmp;
    //std::cout << "  " << chef::stringify_stl_vector(nums) << std::endl;
    help(nums, i);
  }
public:
    int firstMissingPositive(vector<int>& nums) {
      if (nums.empty()) { return 1; }

      for (std::size_t i = 0; i < nums.size(); i++) {
        //std::cout << chef::stringify_stl_vector(nums) << std::endl;
        help(nums, i);
      }

      for (std::size_t i = 0; i < nums.size(); i++) {
        if (nums[i]-1 != i) {
          return i+1;
        }
      }
      return nums.size()+1;
    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<int> nums({3, 4, -1, 1});
  std::cout << s.firstMissingPositive(nums) << std::endl;
  return 0;
}
#endif
