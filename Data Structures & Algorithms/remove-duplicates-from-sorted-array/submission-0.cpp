class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // search from begin(), 
        // if duplicate move pointer
        // if unique change position to duplicated pointer 
        // O(N)
        int bp = 0;
        int cp = 1;
        int n = nums.size();
        while (cp < n) {
            if (cp < n && nums[bp] == nums[cp]) cp++;
            else {
                nums[bp+1] = nums[cp];
                bp++;
                cp++;
            }
        } // 1 2 1 2 3 
        return bp+1;
    }
};