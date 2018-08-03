// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]



// [1,0,-1,0,-2,2]  0
// [5,5,3,5,1,-5,1,-2]  4
class Solution {
  private:
    void append(std::vector<std::vector<int> > &vec, int a, int b, int c) {
      std::vector<int> v;
      v.push_back(a);
      v.push_back(b);
      v.push_back(c);
      vec.push_back(v);
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target) {
      vector<vector<int> > ret;

      if (nums.size() < 3) { return ret; }

      /// sorted outside already.
      //std::sort(nums.begin(), nums.end());

      for (std::size_t i = 0; i < nums.size()-2; i++) {
        if (i != 0 && nums[i] == nums[i-1]) { continue; }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          if (j != (i+1) && nums[j] == nums[j-1]) { j++; continue; }
          if (k != (nums.size()-1) && nums[k] == nums[k+1]) { k--; continue; }

          int sum = nums[i] + nums[j] + nums[k];
          if (sum == target) { append(ret, nums[i], nums[j], nums[k]); j++; k--; }
          else if (sum < target) { j++; }
          else if (sum > target) { k--; }
        }

      }

      return ret;

    }

  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      std::vector<vector<int> > ret;

      if (nums.size() < 4) { return ret; }

      std::sort(nums.begin(), nums.end());

      for (std::size_t i = 0; i < nums.size()-3; i++) {
        if (i != 0 && nums[i] == nums[i-1]) { continue; }

        vector<int> sub_nums;
        for (std::size_t j = i+1; j < nums.size(); j++) { sub_nums.push_back(nums[j]); }

        vector<vector<int> > ts = threeSum(sub_nums, target - nums[i]);
        if (!ts.empty()) {
          for (std::size_t k = 0; k < ts.size(); k++) {
            ts[k].insert(ts[k].begin(), nums[i]);
          }

          ret.insert(ret.end(), ts.begin(), ts.end());
        }
      }

      return ret;

    }
};
