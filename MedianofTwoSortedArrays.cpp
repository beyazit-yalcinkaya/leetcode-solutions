class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedv;
        int s1 = nums1.size(), s2 = nums2.size(), n, i, j;
        n = s1 + s2;
        for (i = 0, j = 0; i < s1 and j < s2;)
        {
            if (nums1[i] < nums2[j])
            {
                mergedv.push_back(nums1[i++]);
            }
            else if (nums1[i] > nums2[j])
            {
                mergedv.push_back(nums2[j++]);
            }
            else
            {
                mergedv.push_back(nums1[i++]);
                mergedv.push_back(nums2[j++]);
            }
        }
        while (i < s1)
        {
            mergedv.push_back(nums1[i++]);
        }
        while (j < s2)
        {
            mergedv.push_back(nums2[j++]);
        }
        if (n % 2) return mergedv[n / 2];
        else return (mergedv[n / 2 - 1] + mergedv[n / 2]) / 2.0;
    }
};