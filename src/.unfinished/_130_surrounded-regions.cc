Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to
'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two
cells are connected if they are adjacent cells connected horizontally or vertically.



class Solution {
public:
    void solve(vector<vector<char>>& board) {
      if (board.empty() || board[0].empty()) { return; }

      for (int i = 1; i < board.size()-1; i++) {
        for (int j = 1; j < board[0].size()-1; j++) {

        }
      }
    }
};
