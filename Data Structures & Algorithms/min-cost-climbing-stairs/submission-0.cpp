class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 0 아니면 1에서 시작, 시작하면 돈지불, 지불했으면 계단 한개 아니면 두개 올라갈수있음
        // 이때 정상에 도달하기 위한 최소값 구하기 
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n ; i++) {
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        }

        dp[n] = min(dp[n-1], dp[n-2]);

        return dp[n];
    }
};
