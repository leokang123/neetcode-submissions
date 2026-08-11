class Solution {
public:
    int visX[9];
    int visY[9];
    int visDL[15]; // 왼오 대각 -> x-y+3
    int visDR[15]; // 오왼 대각 -> x+y 
    vector<string> board;

    vector<vector<string>> result;



    void unCheckVis(int cx, int cy, int n) {
        visX[cx] = 0;
        visY[cy] = 0;
        visDL[cx - cy + n-1] = 0;
        visDR[cx + cy] = 0;
    }

    bool checkVis(int cx, int cy, int n) {
        if (visX[cx] || visY[cy] || visDL[cx - cy + n-1] || visDR[cx+cy]) return false;

        visX[cx] = 1;
        visY[cy] = 1;
        visDL[cx - cy + n-1] = 1;
        visDR[cx + cy] = 1;

        return true;
    }
    void dfs(int level, int n) {
        if (level == n) {
            result.push_back(board);
            return ;
        }

        for (int i = 0 ; i < n ; i++) {
            int cy = level;
            int cx = i;
            if (!checkVis(cx, cy, n)) continue;
            board[cy][cx] = 'Q';
            dfs(level+1, n);
            board[cy][cx] = '.';
            unCheckVis(cx, cy, n);
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        // 퀸 놓았을때 못놓는 자리 체크를 해주는 함수 필요 
        // 다 돌았을때 n개를 못쓰면 백트래킹 
        // 이제 순회를 diagonal로 하거나 행간으로 하던가 둘중 하나인데 하나 택해야할듯 
        // 대각이나 정방향 을 전부 vis 처리하는것보단 
        // 네개 vis를 두고 거기에 하나를 기록하는 느낌으로 처리하면 빠를듯 
        string base = "";
        for (int i = 0 ; i < n ; i++) {
            base += '.';
        }

        board.assign(n, base);

        dfs(0, n);

        return result;


    }
};
