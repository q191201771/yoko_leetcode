Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or
vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int wm[256] = {0};
      int count = 0;
      for (int i = 0; i < word.length(); i++) {
        wm[word[i]]++;
        count++;
      }
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          if (wm[board[i][j]] > 0) {
            wm[board[i][j]]--;
            if (--count == 0) { return true; }
          }
        }
      }
      return false;
    }
};
