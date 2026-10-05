class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0,r = 0,n = nums1.size(),m = nums2.size();
        vector<int> v;
        while(l < n && r < m){
            if(nums1[l] <= nums2[r]){
                v.push_back(nums1[l++]);
            }
            else v.push_back(nums2[r++]);
        }
        while(l < n) v.push_back(nums1[l++]);
        while(r < m) v.push_back(nums2[r++]);
        if((n + m)&1){
            return double(v[(n + m)/2]);
        }
        else {
            return (double(v[(n + m)/2]) + double(v[(n + m)/2 - 1]))/2;
        }
    }
};
