// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
// Input: [10,2]
// Output: "210"
// Example 2:
//
// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of an integer.



class Solution {
public:
    string largestNumber(vector<int>& nums) {
      bool all_zero = true;
      vector<string> ns;
      for (int i = 0; i < nums.size(); i++) {
        ns.emplace_back(std::to_string(nums[i]));
        if (nums[i] != 0) { all_zero = false; }
      }
      if (all_zero) { return "0"; }

      std::sort(ns.begin(), ns.end(), [](const std::string &a, const std::string &b) -> bool {
        return a+b > b+a;
      });

      string ret;
      for (int i = 0; i < ns.size(); i++) {
        ret += ns[i];
      }
      return ret;
    }
};
