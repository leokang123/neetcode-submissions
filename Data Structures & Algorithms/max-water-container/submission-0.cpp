class Solution {
public:
    int maxArea(vector<int>& heights) {
        // brute force? 
        int maxNum = 0;
        int l = 0;
        int r = heights.size() - 1;
        for (int i = 0 ; i < r ; i++) {
            for (int h = i+1 ; h <= r; h++) {
                int cal = (h - i) * min(heights[i], heights[h]);
                if (maxNum < cal) maxNum = cal;
            }
        }
        return maxNum;
    }
};
