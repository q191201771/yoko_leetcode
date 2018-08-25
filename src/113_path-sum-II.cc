Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]



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
  void help(TreeNode *root, int sum, vector<int> one, vector<vector<int> > &ret) {
    if (!root) { return; }

    one.push_back(root->val);
    if (root->left == NULL && root->right == NULL && sum == root->val) {
      ret.push_back(one);
      return;
    }

    help(root->left, sum-root->val, one, ret);
    help(root->right, sum-root->val, one, ret);
  }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int> > ret;
      vector<int> one;
      help(root, sum, one, ret);
      return ret;
    }
};
