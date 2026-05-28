class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            for (int i = l ; i < r ; i++) {
                if (nums[r] == nums[i]) return true;
            }
            if (r-l >= k) l++;
            r++;
        }
        return false;
    }
};