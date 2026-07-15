class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxVal = 0;
        while (l < r) {
            int space = (r-l) * min(heights[l], heights[r]);
            maxVal = max(maxVal, space);
            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return maxVal;
    }
};
