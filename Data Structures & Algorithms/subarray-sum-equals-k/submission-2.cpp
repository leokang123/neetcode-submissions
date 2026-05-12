class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        vector<int> arr = nums;
        for (int i = 1 ; i < nums.size() ; i++) {
            nums[i] += nums[i-1];
        }
        int base = 0;
        for (int j = 0 ; j < nums.size() ; j++) {
            for (int i = j ; i < nums.size() ; i++){
                if (nums[i]-base == k) res++;
                // cout << nums[i] - base << ' ' ;
            }
            // cout << '\n';
            base += arr[j];
            // cout << base << '\n';
        }
        return res; 
    }
};