class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // 아무리 많아도 반복되는 구조 
        k %= n;
        int x = n - k;
        // 1,2,3,4,5,6,7,8
        // k = 6, 3,4,5,6,7,8,1,2
        // x = n - k = 2 
        // how to satisfy O(N) time, O(1) space?

        for (int i = 0 ; i < x; i++) {
            int t = nums[0];
            for (int j = 1; j < n ; j++) {
                nums[j-1] = nums[j];
            }
            nums[n-1] = t;
        }

    }
};