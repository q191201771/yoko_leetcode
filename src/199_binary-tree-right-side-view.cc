// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
// ordered from top to bottom.
//
// Example:
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---



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
  void help(TreeNode *node, int deep, vector<int> &v) {
    if (!node) { return; }

    if (v.size() < deep+1) { v.push_back(0); }
    v[deep] = node->val;
    help(node->left, deep+1, v);
    help(node->right, deep+1, v);
  }
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> v;
      help(root, 0, v);
      return v;
    }
};
