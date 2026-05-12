class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 0;
        for (int n : nums) {
            if (candidate == n) cnt++;
            else cnt--;
            if (cnt == 0) {
                candidate = n;
                cnt = 1;
            }
        }

        return candidate;
    }
};