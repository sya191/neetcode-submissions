class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // create frequency count array for each row/col
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        // create frequency count array for each subbox (3x3)
        vector<vector<vector<int>>> subbox(3, vector<vector<int>>(3, vector<int>(10, 0)));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int dig = board[i][j] - '0';
                // check row
                if (row[i][dig]++ == 1) {
                    return false;
                }

                // check col
                if (col[j][dig]++ == 1) {
                    return false;
                }

                // check subbox
                int srow = i / 3;
                int scol = j / 3;
                if (subbox[srow][scol][dig]++ == 1) {
                    return false;
                }
            }
        }

        return true;
    }
};
