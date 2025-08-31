class Solution {
public:
    /*bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig || board[row][i] == dig) return false;
        }
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if(board[i][j] == dig) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true;
        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }
        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }
        for(char dig = '1'; dig <= '9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }*/
    bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solve(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solve(board))
              return true;
            else
              board[i][j] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
