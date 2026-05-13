class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), l = 0, r = 0;
        int t = target - numbers[l];
        while (r < n) {
            if (l == r) {
                r++;
                continue;
            }
            while (r < n && numbers[r] < t) r++;
            
            if (numbers[r] == t) {
                return {l+1, r+1};
            } else {
                l++;
                t = target - numbers[l];
                r = l+1;
            }
        }
        return {};
    }
};
