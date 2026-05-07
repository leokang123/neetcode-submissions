class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // first try just search 
        unordered_map<int, int> us;
        for (int i = 0 ; i < nums.size() ; i++) us[nums[i]] = i;
        for (int i = 0 ; i < nums.size() ; i++) {
            int tr = target - nums[i];
            int j = us[tr];
            if (i == j || j == 0) continue;
            return {i, us[tr]};
        }
    }
};
