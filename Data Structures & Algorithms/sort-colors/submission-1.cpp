class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> res(3, 0);
        for (auto n : nums) res[n]++;
        int idx = 0;
        for (int i = 0 ; i < 3 ; i++) {
            int cnt = res[i];
            // cout << cnt << '\n';
            for (int j = 0 ; j < cnt ; j++) nums[idx++] = i;
        }
    }
};