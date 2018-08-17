// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// Note:
//
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
// Example:
//
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
//
// Output: [1,2,2,3,5,6]



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int d = nums1.size()-m;
      for (int i = m-1; i >= 0; i--) {
        nums1[i+d] = nums1[i];
      }
      //std::cout << chef::stringify_stl_vector(nums1) << std::endl;
      //std::cout << "d:" << d << std::endl;

      int j = 0;
      int index = 0;
      for (; d < nums1.size() || j < n; ) {
        if (d < nums1.size()) {
          if (j < n) {
            if (nums1[d] < nums2[j]) {
              nums1[index] = nums1[d];
              d++;
            } else {
              nums1[index] = nums2[j];
              j++;
            }
          } else {
            nums1[index] = nums1[d];
            d++;
          }
        } else {
          if (j < n) {
            nums1[index] = nums2[j];
            j++;
            std::cout << "~index:" << index << std::endl;
          } else {
            break;
          }
        }
        index++;
      }

    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<int> nums1({-12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
  vector<int> nums2({-49,-45,-42,-41,-40,-39,-39,-39,-38,-36,-34,-34,-33,-33,-32,-31,-29,-28,-26,-26,-24,-21,-20,-20,-18,-16,-16,-14,-11,-7,-6,-5,-4,-4,-3,-3,-2,-2,-1,0,0,0,2,2,6,7,7,8,10,10,13,13,15,15,16,17,17,19,19,20,20,20,21,21,22,22,24,24,25,26,27,29,30,30,30,35,36,36,36,37,39,40,41,42,45,46,46,46,47,48});
  int m = 1;
  int n = 90;
  //vector<int> nums1({1,2,3,0,0,0});
  //vector<int> nums2({2,5,6});
  //int m = 3;
  //int n = 3;
  std::cout << "nums1.size:" << nums1.size() << ",nums2.size:" << nums2.size() << std::endl;
  s.merge(nums1, m, nums2, n);
  std::cout << chef::stringify_stl_vector(nums1) << std::endl;
  return 0;
}
#endif
