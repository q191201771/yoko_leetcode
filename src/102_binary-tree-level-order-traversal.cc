// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]



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
  void help(TreeNode *root, int index, vector<vector<int> > &ret) {
    if (!root) { return; }

    if (ret.size() <= index) { ret.push_back(vector<int>()); }

    ret[index].push_back(root->val);
    help(root->left, index+1, ret);
    help(root->right, index+1, ret);
  }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int> > ret;
      help(root, 0, ret);
      return ret;
    }
};
