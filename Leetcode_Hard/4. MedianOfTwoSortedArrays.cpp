class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = n1;
        while(low <= high){
            int part1 = (low + high) / 2;
            int part2 = (n1 + n2 + 1) / 2 - part1;

            int max1 = (part1 == 0) ? INT_MIN : nums1[part1-1];
            int max2 = (part2 == 0) ? INT_MIN : nums2[part2-1];
            int min1 = (part1 == n1) ? INT_MAX : nums1[part1];
            int min2 = (part2 == n2) ? INT_MAX : nums2[part2];

            if (max1 <= min2 && max2 <= min1) {
                if ((n1 + n2) % 2 == 0) {
                    return (double)(max(max1, max2) + min(min1, min2)) / 2;
                } else {
                    return (double)max(max1, max2);
                }
            } else if (max1 > min2) {
                high = part1 - 1;
            } else {
                low = part1 + 1;
            }
        }
        return -1;
    }
};
