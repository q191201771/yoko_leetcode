// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  void help(vector<int> &nums, int index, vector<int> &one, vector<vector<int> > &ret) {
    if (index == nums.size()) { return; }

    for (int i = index; i< nums.size(); i++) {
      if (i > index && nums[i] == nums[i-1]) { continue; }

      one.push_back(nums[i]);
      ret.push_back(one);
      help(nums, i+1, one, ret);
      one.pop_back();
    }
  }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> one;
      vector<vector<int> > ret;
      ret.push_back(one);
      std::sort(nums.begin(), nums.end());
      help(nums, 0, one, ret);
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  vector<int> vec({1,2,2});
  Solution s;
  auto ret = s.subsetsWithDup(vec);
  //std::cout << "ret:" << chef::stringify_stl(ret) << std::endl;
  return 0;
}
#endif
