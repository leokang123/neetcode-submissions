class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // first try just search 
        unordered_map<int, int> us;
        for (int i = 0 ; i < nums.size() ; i++) us[nums[i]] = i;
        for (int i = 0 ; i < nums.size() ; i++) {
            int tr = target - nums[i];
            auto it = us.find(tr);
            if (it == us.end()) continue;
            
            int j = it->second;
            if (i == j) continue;
            return {i, j};
        }
    }
};
