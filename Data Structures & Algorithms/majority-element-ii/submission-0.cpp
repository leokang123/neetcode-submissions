class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n/3;
        // first try just use unordered_map(violation O(1) space limit) 
        unordered_map<int, int> mp;
        vector<int> res;
        for (auto n : nums) mp[n]++;
        for (auto [k, v] : mp) {
            if (v > limit) res.push_back(k);
        }
        return res;
    }
};