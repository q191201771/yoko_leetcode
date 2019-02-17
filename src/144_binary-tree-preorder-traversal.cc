// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?



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
  void help(TreeNode *p, vector<int> &v) {
    if (!p) { return; }

    v.push_back(p->val);
    help(p->left, v);
    help(p->right, v);
  }
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> v;
      help(root, v);
      return v;
    }
};
