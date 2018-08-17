// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]



class Solution {
  private:
    void help(int index, int ck, int n, int k, vector<int> &one, vector<vector<int> > &ret) {
      if (ck == k) {
        ret.push_back(one);
        return;
      }

      for (int i = index; i <= n; i++) {
        one.push_back(i);
        help(i+1, ck+1, n, k, one, ret);
        one.pop_back();
      }
    }

public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int> > ret;
      vector<int> one;
      help(1, 0, n, k, one, ret);
      return ret;
    }
};
