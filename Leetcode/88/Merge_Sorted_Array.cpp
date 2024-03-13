//Solution 1
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

//Solution 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = nums1.size();
        while(m || n){
            if(!m){
                nums1[total - 1] = nums2[n - 1];
                n--;
            }
            else if(!n){
                nums1[total - 1] = nums1[m - 1];
                m--;
            }
            else{
                if(nums1[m - 1] > nums2[n - 1]){
                    nums1[total - 1] = nums1[m - 1];
                    m--;
                }
                else{
                    nums1[total - 1] = nums2[n - 1];
                    n--;
                }
            }
            total--;
        }
    }
};

//Solution 3
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i < m + n; i++){
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
    }
};

//Solution 4
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec(m, 0);
        for(int i = 0; i < m ; i++){
            vec[i] = nums1[i];
        }
        int first = 0;
        int second = 0;
        int idx = 0;
        for(int i = 0; i < m + n; i++){
            if(first >= m || second >= n) break;
            if(vec[first] < nums2[second]){
                nums1[i] = vec[first++];
            }
            else{
                nums1[i] = nums2[second++];
            }
            idx++;
        }
        while(first < m){
            nums1[idx++] = vec[first++];
        }
        while(second < n){
            nums1[idx++] = nums2[second++];
        }
    }
};