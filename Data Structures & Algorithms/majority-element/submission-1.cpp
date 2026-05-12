class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 0;
        for (int n : nums) {
            if (cnt > 0 && candidate == n) cnt++;
            else if (cnt == 0) {
                candidate = n;
                cnt = 1;
            } else {
                cnt--;
            }
        }

        return candidate;
    }
};