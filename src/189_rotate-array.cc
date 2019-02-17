// Given an array, rotate the array to the right by k steps, where k is non-negative.
//
// Example 1:
//
// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:
//
// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
// Note:
//
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// Could you do it in-place with O(1) extra space?



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      if (nums.empty() || k < 0) { return; }

      int n = nums.size();
      k %= n;
      int count = 0;

      for (int i = 0; i < k; i++) {
        std::cout << "i:" << i << std::endl;
        int h = i;
        int next = (i+k) % n;
        int l = nums[h];

        for (; ; ) {
          int r = nums[next];
          nums[next] = l;
          l = r;
          if (++count == n) { return; }
          std::cout << chef::stringify_stl(nums) << std::endl;

          next = (next+k) % n;

          if (next == h) {
            nums[h] = l;
            std::cout << chef::stringify_stl(nums) << std::endl;
            if (++count == n) { return; }
            else { break; }
          }
        }
      }
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<int> v({1,2,3,4,5,6,7}); // 3
  //vector<int> v({-1,-100,3,99}); // 2
  //vector<int> v({1,2,3,4,5,6}); // 4
  std::cout << "origin:" << chef::stringify_stl(v) << std::endl;
  s.rotate(v, 3);
  std::cout << "result:" << chef::stringify_stl(v) << std::endl;
  return 0;
}
#endif
