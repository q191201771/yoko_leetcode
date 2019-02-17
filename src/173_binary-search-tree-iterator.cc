// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
// Calling next() will return the next smallest number in the BST.
//
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
  void help(TreeNode *root) {
    if (!root) { return; }

    help(root->left);
    v_.push_back(root->val);
    help(root->right);
  }

private:
  std::vector<int> v_;
  int i_;

public:
    BSTIterator(TreeNode *root) {
      i_ = 0;
      help(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return i_ < v_.size();
    }

    /** @return the next smallest number */
    int next() {
      return v_[i_++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
