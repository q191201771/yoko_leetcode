// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:
//
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.



#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      set<int> rets;
      int l = 0x7FFFFFFF;
      int r = -1;
      for (int i = 0; i < prices.size(); i++) {
        if (r == -1) {
          if (prices[i] <= l) {
            l = prices[i];
          } else {
            r = prices[i];
          }
        } else {
          if (prices[i] >= r) {
            r = prices[i];
          } else {
            rets.insert(r-l);
            l = prices[i];
            r = -1;
          }
        }
      }
      if (r != -1) {
        rets.insert(r-l);
      }
      std::cout << chef::stringify_stl(rets) << std::endl;
      if (rets.empty()) { return 0; }
      if (rets.size() == 1) { return *(rets.begin()); }
      else { return *(rets.begin()) + *(++rets.begin()); }
    }
};
#ifdef YOKO_DEBUG
int main() {
  vector<int> vec({3,3,5,0,0,3,1,4}); // 6
  int ret = Solution().maxProfit(vec);
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
