// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      int num = 1;
      int jl = 0;
      int jr = n-1;
      int iu = 0;
      int id = n-1;
      vector<int> one(n, 0);
      vector<vector<int> > ret;
      for (int i = 0; i < n; i++) {
        ret.push_back(one);
      }
      for (; ; ) {
        if (jl == jr && iu == id) {
          ret[iu][jl] = num;
          return ret;
        }

        for (int j = jl; j < jr; j++) {
          ret[iu][j] = num++;
          if (num > n*n) { return ret; }
        }

        for (int i = iu; i < id; i++) {
          ret[i][jr] = num++;
          if (num > n*n) { return ret; }
        }

        for (int j = jr; j > jl; j--) {
          ret[id][j] = num++;
          if (num > n*n) { return ret; }
        }

        for (int i = id; i > iu; i--) {
          ret[i][jl] = num++;
          if (num > n*n) { return ret; }
        }

        jl++;jr--;iu++;id--;
      }
    }
};
