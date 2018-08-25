// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right
// to left for the next level and alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
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

    if (index % 2 == 0) { ret[index].push_back(root->val); }
    else { ret[index].insert(0, root->val); }

    help(root->left, index+1, ret);
    help(root->right, index+1, ret);
  }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int> > ret;
      help(root, 0, ret);
      return ret;
    }
};
