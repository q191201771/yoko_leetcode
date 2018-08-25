Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.



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
  bool help(TreeNode *l, TreeNode *r) {
    if (!l && !r) { return true; }

    if ((l && !r) || (!l && r)) { return false; }

    return (l->val == r->val) && help(l->left, r->right) && help(l->right, r->left);
  }

public:
    bool isSymmetric(TreeNode* root) {
      if (!root) { return true; }

      return help(root->left, root->right);
    }
};
