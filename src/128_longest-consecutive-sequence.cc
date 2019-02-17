// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if (nums.size() <= 1) { return nums.size(); }

      set<int> s;
      for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
      }

      int prev;
      int max = 1;
      int count = 1;
      set<int>::iterator iter = s.begin();
      for (; iter != s.end(); iter++) {
        if (iter == s.begin()) {
          prev = *iter;
          continue;
        }
        if (*iter == prev+1) {
          count++;
          if (count > max) {
            max = count;
          }
        } else {
          count = 1;
        }
        prev = *iter;
      }
      return max;
    }
};
