class Solution {
public:
    int vis[17];
    int isTrue = 0;
    void dfs (vector<int>& nums, int target, int prev, int sum, int cnt, int k) {
        if (isTrue) return ;
        if (cnt == k) {
            isTrue = 1;
            return ;
        }
        for (int i = prev; i < nums.size() ; i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            if (sum + nums[i] > target) {
                vis[i] = 0;
                continue;
            }
            if (sum + nums[i] == target) {
                dfs(nums, target, 0, 0, cnt+1, k);
            } else {
                dfs(nums, target, i+1, sum + nums[i], cnt, k);
            }
            vis[i] = 0;
        }

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 문제가 혹시 모든 요소를 다 써야하는건가? 근데 쪼갰을때 k개 의 subset이 나와야한다는 말인가? 
        int total = 0;
        for (auto num : nums) total += num;
        if (total % k != 0) return false;
        int target = total / k;
        dfs(nums, target, 0, 0, 0, k);

        return isTrue == 1;
    }
};