// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Note:
//
// You can assume that you can always reach the last index.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  int __max(int x, int y) { return x > y ? x : y; }
public:
    int jump(vector<int>& nums) {
      if (nums.size() < 2) { return 0; }

      int m = 0;
      int end = 0;
      int count = 0;
      for (int i = 0; i < nums.size(); i++) {
        m = __max(m, i+nums[i]);
        if (m >= nums.size()-1) {
          count++;
          break;
        }

        if (i == end) {
          count++;
          end = m;
        }
      }
      return count;
    }
};

#ifdef YOKO_DEBUG
int main() {
  Solution s;
  //vector<int> vec({0});
  //vector<int> vec({1,2,3});
  //vector<int> vec({2,3,1,1,4});
  //vector<int> vec({1,1,1,1,1});
  vector<int> vec({2,3,1});

  std::cout << s.jump(vec) << std::endl;
  return 0;
}
#endif
