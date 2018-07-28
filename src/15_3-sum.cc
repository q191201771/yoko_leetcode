// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]



// [-1, 0, 1, 2, -1, -4]
class Solution {
private:
  void append(std::vector<std::vector<int> > &vec, int a, int b, int c) {
    std::vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    vec.push_back(v);
  }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int> > ret;

      if (nums.size() < 3) { return ret; }

      std::sort(nums.begin(), nums.end());

      for (std::size_t i = 0; i < nums.size()-2; i++) {
        if (i != 0 && nums[i] == nums[i-1]) { continue; }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          if (j != (i+1) && nums[j] == nums[j-1]) { j++; continue; }
          if (k != (nums.size()-1) && nums[k] == nums[k+1]) { k--; continue; }

          int sum = nums[i] + nums[j] + nums[k];
          if (sum == 0) { append(ret, nums[i], nums[j], nums[k]); j++; k--; }
          else if (sum < 0) { j++; }
          else if (sum > 0) { k--; }
        }

      }

      return ret;

    }
};
