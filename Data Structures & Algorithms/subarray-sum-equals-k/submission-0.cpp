class Solution {
public:

    int subarraySum(vector<int>& nums, int k) { 
        int res = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            vector<int> arr(nums.begin() + i, nums.end());
            if (arr[0] == k) res++;
            for (int j = 1 ; j < arr.size() ; j++) {
                arr[j] += arr[j-1];
                if (arr[j] == k) res++;
            }
        }
        return res;
    }
};