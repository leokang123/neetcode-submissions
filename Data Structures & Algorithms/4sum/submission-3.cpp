class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // -3 0 1 2 3 3 
        // -1 -1 -1 1 1 1 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0 ; i < n-3 ; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-2 ; j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int base = nums[i] + nums[j];
                int l = j+1;
                int r = n-1;
                while (l < r) {
                    long long sum = (long long)base + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l + 1 < r && nums[l+1] == nums[l]) l++;
                        while (l < r - 1 && nums[r-1] == nums[r]) r--;
                        l++;
                        r--;
                    } else if (sum < target) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};