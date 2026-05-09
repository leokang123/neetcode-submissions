class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        // no idea except making array with pair
        vector<pair<int,int>> res(2001, {0, 0});
        int base = 1000;
        for (auto n : nums) res[base + n] = {base+n, res[base+n].second+1};
        sort(res.begin(), res.end(), [](const pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
        for (int i = 0 ; i < k ; i++) {
            result.push_back(res[i].first-base);
        }
        return result;
    }
};
