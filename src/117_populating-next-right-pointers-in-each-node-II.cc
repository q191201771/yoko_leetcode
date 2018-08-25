// Given a binary tree
//
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.
// Example:
//
// Given the following binary tree,
//
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL



/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
  void help(TreeLinkNode *root, int index, vector<TreeLinkNode *> &prevs) {
    if (!root) { return; }

    if (prevs.size() <= index) { prevs.push_back(NULL); }

    if (prevs[index]) {
      prevs[index]->next = root;
    }
    prevs[index] = root;

    help(root->left, index+1, prevs);
    help(root->right, index+1, prevs);
  }
public:
    void connect(TreeLinkNode *root) {
      vector<TreeLinkNode *> prevs;
      help(root, 0, prevs);
    }
};