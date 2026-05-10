class Solution {
public:
    bool checkRow(vector<vector<char>>& board) {
        for (int c = 0 ; c < 9 ; c++) {
            vector<int> checkNum(9, 0);
            for (int r = 0 ; r < 9 ; r++) {
                char num = board[r][c];
                if (num == '.') continue;
                if (checkNum[num-'0'-1]) return false;
                checkNum[num-'0'-1]++;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board) {
        for (int r = 0 ; r < 9 ; r++) {
            vector<int> checkNum(9, 0);
            for (int c = 0 ; c < 9 ; c++) {
                char num = board[r][c];
                if (num == '.') continue;
                if (checkNum[num-'0'-1]) return false;
                checkNum[num-'0'-1]++;
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board) {
        for (int i = 0 ; i < 9 ; i++) {
            vector<int> checkNum(9, 0);
            for(int r = 0 ; r < 3 ; r++) {
                for (int c = 0 ; c < 3 ; c++) {
                    int row = (i/3)*3 + r;
                    int col = (i%3)*3 + c;
                    char num = board[row][col];
                    if (num == '.') continue;
                    if (checkNum[num-'0'-1]) return false;
                    checkNum[num-'0'-1]++;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkCol(board) && checkRow(board) && checkBox(board);
    }
};
