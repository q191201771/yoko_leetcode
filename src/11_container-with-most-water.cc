// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical
// lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with
// x-axis forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
//
// Example:
//
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

//
//
//
//
//
//     *              *
//     *              *     *
//     *  *           *     *
//     *  *     *     *     *
//     *  *     *  *  *     *
//     *  *     *  *  *  *  *
//     *  *  *  *  *  *  *  *
//  *  *  *  *  *  *  *  *  *

class Solution {
private:
  int max(int x, int y) { return x > y ? x : y; }
  int min(int x, int y) { return x < y ? x : y; }

public:
    int maxArea(vector<int>& height) {
      int i = 0;
      int j = height.size() - 1;
      int water = 0;
      while (i < j) {
        int l = min(height[i], height[j]);
        water = max(water, l * (j - i));
        while (i < j && height[i] <= l) { i++; }
        while (i < j && height[j] <= l) { j--; }
      }
      return water;

    }
};
