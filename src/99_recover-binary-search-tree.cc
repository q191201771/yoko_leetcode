// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
// Example 2:
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
// Follow up:
//
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?



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
    void help(TreeNode *root, TreeNode **prev, TreeNode **s, TreeNode **b) {
      if (!root) { return; }

      help(root->left, prev, s, b);

      if (*prev) {
        if ((*prev)->val > root->val) {
          if (*s == NULL) {
            *s = *prev;
          }
          *b = root;
        }
      }
      *prev = root;

      help(root->right, prev, s, b);
    }

public:
    void recoverTree(TreeNode* root) {
      TreeNode *prev = NULL;
      TreeNode *s = NULL;
      TreeNode *b = NULL;
      help(root, &prev, &s, &b);
      if (s && b) {
        int val = s->val;
        s->val = b->val;
        b->val = val;
      }
    }
};
