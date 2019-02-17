// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once.
// Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
// Input: [2,2,3,2]
// Output: 3
// Example 2:
//
// Input: [0,1,0,1,0,1,99]
// Output: 99



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int count[32] = {0};
      int ret = 0;

      for (int i = 0; i < 32; i++) {
        for (int j = 0; j < nums.size(); j++) {
          count[i] += ((nums[j] >> i) & 1);
        }
        ret += ((count[i] % 3) << i);
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  //vector<int> vec({2,2,3,2});
  vector<int> vec({0,1,0,1,0,1,99});
  int ret = s.singleNumber(vec);
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
