class Solution {
public:
    int rob(vector<int>& nums) {
        // nums[i] nums[i-2] nums[i-3] 
        int n = nums.size();
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if (n > 1) dp[1] = nums[1];
        if (n > 2) dp[2] = nums[0] + nums[2];
        for (int i = 3; i < n ; i++) {
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        if (n == 1) return dp[0];
        return max(dp[n-1], dp[n-2]);
        
    }
};
