class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }

private:
    void heapify(vector<int>& nums, int n, int idx) {
        while(true) {
            int left = (idx << 1) + 1;
            int right = (idx << 1) + 2;
            int largest = idx;

            if (left < n && nums[left] > nums[largest]) largest = left;
            if (right < n && nums[right] > nums[largest]) largest = right;
            if (largest == idx) break;
            swap(nums[largest], nums[idx]);
            idx = largest;
        }
    }
    // 0   1 2   3

    void heapsort(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1 ; i >= 0 ; i--) heapify(nums, n, i);
        for (int i = n - 1; i > 0 ; i--) {
            swap(nums[0], nums[i]);
            heapify(nums,i,0);
        }
    }
};