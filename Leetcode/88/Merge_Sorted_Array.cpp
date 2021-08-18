class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0){
            nums1=nums2;
            return;
        }
        int forone=m-1;
        int fortwo=n-1;
        int cur=m+n-1;
        while(forone>=0 || fortwo>=0){
            if(forone<0){
                nums1[cur--]=nums2[fortwo--];
                continue;
            }
            if(fortwo<0){
                nums1[cur--]=nums1[forone--];
                continue;
            }
            if(nums2[fortwo]>=nums1[forone]) nums1[cur--]=nums2[fortwo--];
            else nums1[cur--]=nums1[forone--];
        }
    }
};
