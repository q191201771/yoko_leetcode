// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
      if (!root) { return 0; }

      int l = minDepth(root->left);
      int r = minDepth(root->right);
      if (l == 0 && r == 0) { return 1; }
      else if (l == 0 && r != 0) { return r+1; }
      else if (l != 0 && r == 0) { return l+1; }
      else { return 1+(l < r ? l : r); }
    }
};
