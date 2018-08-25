Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?



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
  void recursive_help(TreeNode *root, vector<int> &ret) {
    if (!root) { return; }

    recursive_help(root->left, ret);
    ret.push_back(root->val);
    recursive_help(root->right, ret);
  }
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ret;
      recursive_help(root, ret);
      return ret;
    }
};
