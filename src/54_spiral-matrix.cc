// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ret;
      if (matrix.empty() || matrix[0].empty()) { return ret; }

      int i;
      int j;
      int jl = 0;
      int jr = matrix[0].size()-1;
      int iu = 0;
      int id = matrix.size()-1;
      for (; jl <= jr || iu <= id; ) {
        if (jl <= jr && iu < matrix.size()) {
          for (j = jl; j <= jr; j++) {
            ret.push_back(matrix[iu][j]);
          }
          if (++iu > id) { return ret; }
        }

        if (iu <= id && jr >= 0) {
          for (i = iu; i <= id; i++) {
            ret.push_back(matrix[i][jr]);
          }
          if (--jr < jl) { return ret; }
        }

        if (jl <= jr && id >= 0) {
          for (j = jr; j >= jl; j--) {
            ret.push_back(matrix[id][j]);
          }
          if (--id > iu) { return ret; }
        }

        if (iu <= id && jl < matrix[0].size()) {
          for (i = id; i >= iu; i--) {
            ret.push_back(matrix[i][jl]);
          }
          if (++jl > jr) { return ret; }
        }
      }
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  Solution s;
  vector<vector<int> > vec;
  //vec.push_back(vector<int>({1,2,3}));
  //vec.push_back(vector<int>({4,5,6}));
  //vec.push_back(vector<int>({7,8,9}));

  //vec.push_back(vector<int>({1,2,3,4}));
  //vec.push_back(vector<int>({5,6,7,8}));
  //vec.push_back(vector<int>({9,10,11,12}));

  vec.push_back(vector<int>({7}));
  vec.push_back(vector<int>({9}));
  vec.push_back(vector<int>({6}));
  auto ret = s.spiralOrder(vec);
  //std::cout << "ret: " << chef::stringify_stl_vector(ret) << std::endl;
  return 0;
}
#endif
