class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0;
        for (int start = 0; count < n ; start++) {
            int current = start;
            int prev = nums[current];
            while(true) {
                int nextIdx = (current + k) % n;
                int nextVal = nums[nextIdx];
                nums[nextIdx] = prev;
                current = nextIdx;
                prev = nextVal;
                count++;
                if (current == start) break;
            }
        }
    }
};