// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it
// is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
// section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6



class Solution {
private:
  int __min(int x, int y) { return x < y ? x : y; }
public:
    int trap(vector<int>& height) {
      if (height.size() <= 2) { return 0; }

      vector<int> lm(height.size(), 0);
      int max = -1;
      for (int i = 0; i < height.size(); i++) {
        if (height[i] > max) {
          max = height[i];
        }
        lm[i] = max;
      }
      vector<int> rm(height.size(), 0);
      max = -1;
      for (int i = height.size()-1; i >= 0; i--) {
        if (height[i] > max) {
          max  = height[i];
        }
        rm[i] = max;
      }

      int ret = 0;
      for (std::size_t i = 1; i < height.size()-1; i++) {
        if (lm[i-1] == 0 || rm[i+1] == 0 || height[i] >= lm[i-1] || height[i] >= rm[i+1]) { continue; }

        ret += (__min(lm[i-1], rm[i+1]) - height[i]);
      }

      return ret;
    }
};
