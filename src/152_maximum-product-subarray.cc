// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the
// largest product.
//
// Example 1:
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
    int __max(int a, int b) { return a > b ? a : b; }
    int __min(int a, int b) { return a < b ? a : b; }
public:
    int maxProduct(vector<int>& nums) {
      if (nums.empty()) { return 0; }

      int ret = nums[0]; int max_num = nums[0]; int min_num = nums[0];

      for (int i = 1; i < nums.size(); i++) {
        int max_num_keeper = max_num;
        int min_num_keeper = min_num;
        max_num = __max(max_num_keeper * nums[i], nums[i]);
        max_num = __max(min_num_keeper * nums[i], max_num);
        min_num = __min(min_num_keeper * nums[i], nums[i]);
        min_num = __min(max_num_keeper * nums[i], min_num);

        ret = __max(ret, max_num);
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<int> v({2,3,-2,4});
  //vector<int> v({-2,0,-1});
  //vector<int> v({-4,-3,-2});
  int ret = s.maxProduct(v);
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
