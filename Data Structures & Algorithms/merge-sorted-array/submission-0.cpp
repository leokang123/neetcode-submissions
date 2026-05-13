class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ap = 0;
        int bp = 0;
        while (bp < n) {
            if (ap < m && nums1[ap] <= nums2[bp]) ap++;
            else if (ap >= m) {
                nums1[ap++] = nums2[bp++];
            }
            else {
                for (int i = m ; i> ap ; i--) {
                    nums1[i] = nums1[i-1];
                }
                nums1[ap] = nums2[bp++];
                m++;
            }
        }
    }
};