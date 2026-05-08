class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if one element goes over half that is the one 
        int target = nums.size()/2+ 1;
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
            if (mp[n] == target) return n;
        }
        return -1;
    }
};