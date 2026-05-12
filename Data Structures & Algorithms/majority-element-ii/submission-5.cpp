class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n/3;
        int candidate1, candidate2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0 ; i < n ; i++) {
            if (cnt1 > 0 && candidate1 == nums[i]) cnt1++;
            else if (cnt2 > 0 && candidate2 == nums[i]) cnt2++;
            else if (cnt1 == 0) {
                candidate1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                candidate2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0 ; i < n ; i++) {
            if (candidate1 == nums[i]) cnt1++;
            if (candidate2 == nums[i]) cnt2++;
        }
        vector<int> res;
        if (cnt1 > limit) res.push_back(candidate1);
        if (cnt2 > limit) res.push_back(candidate2);
        return res;
    }
};