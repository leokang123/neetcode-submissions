class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto n : nums) {
            sum += n;
            int need = sum - k;
            if (mp.find(need) != mp.end()) {
                res += mp[need];
            }
            mp[sum]++;
        }
        return res;
    }
};