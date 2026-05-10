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
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                vector<int> checkNum(9, 0);
                for (int r = i*3; r < i*3+3 ; r++){
                    for (int c = j*3 ; c < j*3+3 ; c++) {
                        char num = board[r][c];
                        if (num == '.') continue;
                        if (checkNum[num-'0'-1]) return false;
                        checkNum[num-'0'-1]++;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkCol(board) && checkRow(board) && checkBox(board);
    }
};
