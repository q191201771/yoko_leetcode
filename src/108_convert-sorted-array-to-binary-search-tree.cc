Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5



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
  TreeNode *help(vector<int> &nums, int l, int r) {
    if (l > r) { return NULL; }

    int m = (l+r) / 2;
    TreeNode *node = new TreeNode(nums[m]);
    node->left = help(nums, l, m-1);
    node->right = help(nums, m+1, r);
    return node;
  }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return help(nums, 0, nums.size()-1);
    }
};
