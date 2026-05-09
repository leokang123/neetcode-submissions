class Solution {
public:
    // in place -> heap or quick sort, merge sort needs temporary memory
    void heapify(vector<int>&nums, int n, int idx) {
        int l = (idx << 1) + 1;
        int r = (idx << 1) + 2;
        int largest = idx; 

        if (l < n && nums[l] > nums[largest]) largest = l;
        if (r < n && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[largest], nums[idx]);
            heapify(nums, n, largest);
        }
    }
    void heapSort(vector<int>&nums) {
        int n = nums.size();
        for (int i = n / 2 - 1 ; i >= 0 ; i--) 
            heapify(nums, n, i);

        for (int i = n-1 ; i > 0 ; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    void sortColors(vector<int>& nums) {
        heapSort(nums);
    }
};