// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and
// sell one share of the stock multiple times).
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
// Input: [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
//              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
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
      int ret = 0;
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
            ret += r-l;
            l = prices[i];
            r = -1;
          }
        }
      }
      return r == -1 ? ret : (ret+r-l);

    }
};
#ifdef YOKO_DEBUG
int main() {
  //vector<int> vec({7,1,5,3,6,4}); // 7
  //vector<int> vec({1,2,3,4,5}); // 4
  //vector<int> vec({7,6,4,3,1}); // 0
  vector<int> vec({6,1,3,2,4,7}); // 7
  int ret = Solution().maxProfit(vec);
  std::cout << "ret:" << ret << std::endl;
  return 0;
}
#endif
