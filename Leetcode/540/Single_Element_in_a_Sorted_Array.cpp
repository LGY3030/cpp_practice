//Solution 1
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int start=0;
        int end=nums.size()-1;
        while(nums[start]==nums[start+1] && nums[end]==nums[end-1]){
            start+=2;
            end-=2;
        }
        if(nums[start]!=nums[start+1]) return nums[start];
        return nums[end];
    }
};

//Solution 2
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(end>start){
            int mid=start+(end-start)/2;
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])) start=mid+1;
            else end=mid;
        }
        return nums[start];
    }
};
