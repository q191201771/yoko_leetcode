// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  void help(vector<int> &nums, int index, vector<vector<int> > &ret, vector<int> &one, set<int> &s) {
    if (index == nums.size()) {
      //std::cout << chef::stringify_stl_vector(one) << std::endl;
      ret.push_back(one);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i-1] && s.find(i-1) == s.end()) { continue; }

      if (s.find(i) != s.end()) { continue; }

      s.insert(i);
      one.push_back(nums[i]);
      help(nums, index+1, ret, one, s);
      s.erase(i);
      one.pop_back();
    }
  }
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
      vector<vector<int> > ret;
      vector<int> one;
      set<int> s;
      sort(nums.begin(), nums.end());
      help(nums, 0, ret, one, s);
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  //vector<int> vec({1,1,2});
  vector<int> vec({3,3,0,3});
  s.permuteUnique(vec);
  return 0;
}
#endif
