class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // -4, -1, -1, 0, 1, 2 

        vector<vector<int>> res;
        set<int> ch;
        int n = nums.size();
        for (int i = 0 ; i < n-2; i++) {
            if (ch.count(nums[i])) continue;
            int base = nums[i];
            ch.insert(nums[i]);
            int fst = i+1;
            int en = n-1;
            while (fst < en) {
                int sum = base + nums[fst] + nums[en];
                if (sum == 0) {
                    res.push_back({nums[i], nums[fst], nums[en]});
                    while (fst + 1 < en && nums[fst] == nums[fst+1]) fst++;
                    fst++;
                    continue; 
                } else if (sum < 0) fst++;
                else en--;
            }
        }
        return res;
    }
};
