// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int ret = -0x7FFFFFFF;
      int sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        sum+=nums[i];
        if (sum > ret) { ret = sum; }
        if (sum < 0) { sum = 0; }
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<int> vec({-2,1,-3,4,-1,2,1,-5,4});
  s.maxSubArray(vec);
  return 0;
}
#endif
