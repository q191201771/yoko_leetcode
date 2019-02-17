// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
// the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
// Example 2:
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef YOKO_DEBUG
#include "util/helper.hpp"
#endif
class Solution {
private:
  int help(TreeNode *root, int &ret) {
      if (!root) { return 0; }

      int m = root->val;
      int mm = root->val;
      int l = help(root->left, ret);
      int r = help(root->right, ret);
      if (l > 0) { m += l; }
      if (r > 0) { m += r; }
      if (m > ret) { ret = m; }
      if (l > 0 || r > 0) { mm += (l > r ? l : r); }

      return mm;

  }
public:
    int maxPathSum(TreeNode* root) {
      int ret = -0x7FFFFFFF-1;
      help(root, ret);
      return ret;
    }
};
#ifdef YOKO_DEBUG
int main() {
  TreeNode *root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  Solution s;
  std::cout << s.maxPathSum(root) << std::endl;
  return 0;
}
#endif
