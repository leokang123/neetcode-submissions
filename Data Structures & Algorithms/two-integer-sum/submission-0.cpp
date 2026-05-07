class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // first try just search 
        for (int i = 0 ; i < nums.size() ; i++) {
            int tr = target - nums[i];
            for (int j = i+1 ; j < nums.size() ; j++) {
                if (tr == nums[j]) return {i, j};
            }
        }
    }
};
