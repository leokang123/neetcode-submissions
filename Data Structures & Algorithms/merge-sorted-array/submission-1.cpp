class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ap = m-1;
        int bp = n-1;
        int pos = m+n-1;
        while(bp >= 0) {
            if (ap >= 0 && nums1[ap] > nums2[bp]) {
                nums1[pos--] = nums1[ap--];
            } else {
                nums1[pos--] = nums2[bp--];
            }
        }
    }
};