//Solution 1
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum=0;
        int slow=0;
        int fast=0;
        int res=nums.size()+1;
        while(fast<nums.size()){
            while(sum<s && fast<nums.size()) {
                sum+=nums[fast];
                fast++;
            }
            while(sum>=s && slow<=fast) {
                res=min(res, fast-slow);
                sum-=nums[slow];
                slow++;
            }
        }
        if(res==nums.size()+1) return 0;
        return res;
    }
};

//Solution 2
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=0;
        int res=nums.size()+1;
        int sum=0;
        while(end<nums.size()){
            sum+=nums[end++];
            while(sum>=target){
                res=min(res, end-start);
                sum-=nums[start++];
            }
        }
        if(res==nums.size()+1) return 0;
        return res;
    }
};
