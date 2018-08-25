// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6



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
private:
  void help(TreeNode *root, TreeNode **ret, TreeNode **prev) {
    if (!root) { return; }

    if (*prev == NULL) { *prev = new TreeNode(root->val); *ret = *prev; }
    else { (*prev)->right = new TreeNode(root->val); *prev = (*prev)->right; }

    help(root->left, ret, prev);
    help(root->right, ret, prev);
  }
public:
    void flatten(TreeNode* root) {
      if (!root) { return; }

      TreeNode *ret = NULL;
      TreeNode *prev = NULL;
      help(root, &ret, &prev);
      root->val = ret->val;
      root->left = NULL;
      root->right = ret->right;
    }
};
