class Solution {
public:
    void rotateOne(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[0];
        for (int i = 1 ; i <= n ; i++) {
            int tmp2 = nums[i%n];
            nums[i%n] = tmp;
            tmp = tmp2;
        }
    }
    void rotate(vector<int>& nums, int k) {
        for (int i = 0 ; i < k ; i++) rotateOne(nums);
    }
};