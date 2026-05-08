class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        vector<int> result;
        for (auto i : nums) {
            if (i == val) continue;
            result.push_back(i);
            cnt++;
        }
        nums = result;
        return cnt;
    }
};