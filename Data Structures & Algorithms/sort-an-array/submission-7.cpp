class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int mid = (left + right) >> 1;
        swap(nums[mid], nums[left+1]);

        // left < left+1 < right
        if (nums[left] > nums[right]) swap(nums[left], nums[right]);
        if (nums[left+1] > nums[right]) swap(nums[left+1], nums[right]);
        if (nums[left] > nums[left+1]) swap(nums[left], nums[left+1]);

        int i = left+1;
        int j = right;
        int pivot = nums[i];

        while(true) {
            while(nums[++i] < pivot) ;
            while(nums[--j] > pivot) ; // 1 5 1 2 2 8 5 5 5 7 9
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }

        // j is same or smaller then pivot 
        nums[left + 1] = nums[j];
        nums[j] = pivot;
        return j;

    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (right <= left + 1) {
            if (left + 1 == right && nums[left] > nums[right]) swap(nums[left], nums[right]);
            return;
        }
        // j position fixed
        int j = partition(nums, left, right);
        quickSort(nums, left, j-1);
        quickSort(nums, j+1, right);


    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};