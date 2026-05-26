class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // cycle array,  O(n) space
        int n = nums.size();
        vector<int> res(n , 0);
        for (int i = 0 ; i < n ; i++) {
            res[(i+k) % n] = nums[i];
        }
        nums = res;
    }
};