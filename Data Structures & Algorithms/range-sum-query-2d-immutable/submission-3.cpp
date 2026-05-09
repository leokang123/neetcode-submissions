class NumMatrix {
private:
    vector<vector<int>> mat{};
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        for (int r = 0 ; r < mat.size() ; r++) {
            int sum = 0;
            for (int c = 0 ; c < mat[0].size() ; c++) {
                sum += mat[r][c];
                mat[r][c] = sum;
            }   
        }

        for (int c = 0 ; c < mat[0].size(); c++) {
            int sum = 0;
            for (int r = 0 ; r < mat.size() ; r++) {
                sum += mat[r][c];
                mat[r][c] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (row1-1 >= 0) {
            sum -= mat[row1-1][col2];
        }
        if (col1-1 >= 0) {
            sum -= mat[row2][col1-1];
        }
        if (row1-1 >= 0 && col1-1 >= 0) {
            sum += mat[row1-1][col1-1];
        }
        sum += mat[row2][col2];
        return sum;
    }
};
 // 2 2 2 
 // 2 2 2 
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */