class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        vector<int> result;
        int idx = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == val) continue;
            nums[idx++] = nums[i];
            cnt++;
        }
        return cnt;
    }
};