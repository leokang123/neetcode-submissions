class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = -1;
        int high = nums.size(); 
        while (low + 1 < high) {
            int mid = (high + low) / 2;
            if (nums[mid] < target) low = mid;
            else high = mid;
        }
        return high;
    }
};