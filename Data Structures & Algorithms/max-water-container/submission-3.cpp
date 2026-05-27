class Solution {
public:
    int maxArea(vector<int>& heights) {
        // brute force? 
        int maxNum = 0;
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            int cal = (r - l) * min(heights[l], heights[r]);
            maxNum = max(maxNum, cal);
            if (heights[l] <= heights[r]) l++;
            else r--;
        }
        return maxNum;
    }
};
