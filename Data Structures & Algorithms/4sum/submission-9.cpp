class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        // -3 0 1 2 3 3 
        for (int i = 0 ; i < n ; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n ; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                long long base = nums[i] + nums[j];
                int l = j+1, r = n-1;
                while (l < r) {
                    long long sum = base + nums[l] + nums[r];
                    if (sum > target) r--;
                    else if (sum < target) l++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l-1]) l++;
                    }
                }
            }
        }
        return ans;
        
    }
};