Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
  void help(TreeNode *p, vector<int> &v) {
    if (!p) { return; }

    help(p->left, v);
    help(p->right, v);
    v.push_back(p->val);
  }
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> v;
      help(root, v);
      return v;
    }
};
