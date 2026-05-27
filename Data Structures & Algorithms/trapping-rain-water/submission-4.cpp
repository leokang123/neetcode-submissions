class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int res = 0;
        while (l <= r) {
            while (l < r && leftMax <= height[l]) leftMax = height[l++];
            while (l < r && rightMax <= height[r]) rightMax = height[r--];
            // cout << leftMax<< ' ' << rightMax << '\n';
            // cout << l << ' ' << r << '\n';
            if (leftMax <= rightMax) {
                int sum = leftMax - height[l++];
                if (sum < 0) continue;
                res += sum;
            } else {
                int sum = rightMax - height[r--];
                if (sum < 0) continue;
                res += sum;
            }
        }
        return res;
    }
};




// find r-val is same or bigger than l-val
// if not find, set r++, and move until r-val is subbiggest
// calculate l, r gap, and move l to r 
