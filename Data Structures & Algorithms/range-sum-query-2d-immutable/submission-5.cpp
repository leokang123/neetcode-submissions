class NumMatrix {
private: 
    vector<vector<int>> prefixMat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        prefixMat = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for (int r = 1; r <= row ; r++) {
            for (int c = 1 ; c <= col ; c++) {
                prefixMat[r][c] = matrix[r-1][c-1] 
                + prefixMat[r-1][c] 
                + prefixMat[r][c-1] 
                - prefixMat[r-1][c-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        return prefixMat[row2][col2]
        - prefixMat[row1-1][col2] 
        - prefixMat[row2][col1-1]
        + prefixMat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */