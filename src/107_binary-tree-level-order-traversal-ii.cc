// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right,
// level by level from leaf to root).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
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

    if (ret.size() <= index) { ret.insert(ret.begin(), vector<int>()); }

    ret[ret.size()-index-1].push_back(root->val);
    help(root->left, index+1, ret);
    help(root->right, index+1, ret);
  }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int> > ret;
      help(root, 0, ret);
      return ret;
    }
};
