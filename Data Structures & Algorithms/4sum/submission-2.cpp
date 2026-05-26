class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // -3 0 1 2 3 3 
        // -1 -1 -1 1 1 1 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<pair<int,int>> uset;
        vector<vector<int>> res;
        for (int i = 0 ; i < n-3 ; i++) {
            for (int j = i+1; j < n-2 ; j++){
                // base가 같지만 두 수가 다른 상황 발생 
                if (uset.count({nums[i],nums[j]})) continue;
                uset.insert({nums[i], nums[j]});
                long long base = nums[i] + nums[j];
                int l = j+1;
                int r = n-1;
                while (l < r) {
                    long long sum = base + nums[l] + nums[r];
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