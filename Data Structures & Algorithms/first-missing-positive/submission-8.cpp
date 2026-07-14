class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // what i interested in 
        // vector size n -> answer bounded in 1~n 
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            // index sorting -> O(n)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                // if nums[i] = n, its position is n-1 in vector swap swap 
                swap(nums[i], nums[nums[i]-1]);
            } 
        }

        for (int i = 0 ; i < n ; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};