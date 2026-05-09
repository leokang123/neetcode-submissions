class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
private: 
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return ;
        int m = (l + r) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> tmp;
        int i = l;
        int j = m+1;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp.push_back(nums[i++]);
            } else {
                tmp.push_back(nums[j++]);
            }
        }

        while (i <= m) tmp.push_back(nums[i++]);
        while (j <= r) tmp.push_back(nums[j++]);

        for (int i = l ; i <= r ; i++) {
            nums[i] = tmp[i-l];
        }
    }
};