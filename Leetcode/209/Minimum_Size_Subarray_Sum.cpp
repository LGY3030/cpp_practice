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
