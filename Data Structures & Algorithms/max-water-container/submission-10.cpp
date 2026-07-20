class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxVal = 0;
        while (left < right) {
            int base = min(heights[left], heights[right]);
            maxVal = max(maxVal, base * (right - left));
            if (base == heights[left]) left++;
            else right--;
        }
        return maxVal;
    }
};
