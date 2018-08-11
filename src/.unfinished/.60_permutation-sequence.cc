The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"



class Solution {
public:
    string getPermutation(int n, int k) {
      string ret;

      int mapping[10];
      int mapping[1] = 1;
      for (int i = 2; i <= n; i++) {
        mapping[i] = mapping[i-1] * i;
      }
      std::string str = "0123456789";
      for (int i = 0; i < n; i++) {
        // k=9 n=4 i=0 mapping[3]=6 k/mapping[3]=1 index=2
        // k=3 n=4 i=1 mapping[2]=2 k/mapping[2]=1 index=2
        // k=1 n=4 i=2 mapping[1]=1 k/mapping[1]=1 index=2
        int index = (k / mapping[n-i-1]) + 1;
        k -= mapping[n-i-1];
        ret += str[index];
        str.erase(index, 1);
      }
    }
};
