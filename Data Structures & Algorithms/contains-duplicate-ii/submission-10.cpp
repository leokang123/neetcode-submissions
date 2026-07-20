class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int idx = 0;
        for (auto num : nums) {
            if (s.find(num) != s.end()) return true;

            if (idx >= k) s.erase(nums[idx-k]);
            s.insert(nums[idx]);
            idx++;
        }
        return false;
    }
};