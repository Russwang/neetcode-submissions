class Solution {
   public:

    bool check(vector<vector<char>>& board, int x, int y) {
        vector<int> count(9,0);
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                // if (count[board[x][y]]++) return false;
                if (board[i][j] != '.' && count[board[i][j] - '1']++) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> row(9, 0);
            vector<int> col(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && row[board[i][j] - '1']++) return false;
                if (board[j][i] != '.' && col[board[j][i] - '1']++) return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!check(board, i * 3, j * 3)) return false;
            }
        }
        return true;
    }
};
