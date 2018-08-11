// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Note:
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another
// 2D matrix and do the rotation.
//
// Example 1:
//
// Given input matrix =
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
//
// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Example 2:
//
// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ],
//
// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  void __swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
  }
public:
    void rotate(vector<vector<int>>& matrix) {
      int s = matrix.size();
      if (s < 2) { return; }

      int b = 0;
      int e = s-1;
      for (int i = 0; i < s; i++) {
        for (int j = b; j < e; j++) {
          __swap(&matrix[i][j], &matrix[i+j-b][e]);
          __swap(&matrix[i][j], &matrix[s-1-i][e-j+b]);
          __swap(&matrix[i][j], &matrix[s-1-j][b]);
        }

        b++;
        e--;
        if (b == e) { return; }
      }
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<vector<int> > v;
  v.push_back(vector<int>({15,13,2,5}));
  v.push_back(vector<int>({14,7,4,1}));
  v.push_back(vector<int>({12,3,8,9}));
  v.push_back(vector<int>({16,6,10,11}));
  std::cout << stringify_two_dimensional_vector(v) << std::endl;
  s.rotate(v);
  std::cout << stringify_two_dimensional_vector(v) << std::endl;
  return 0;
}
#endif
