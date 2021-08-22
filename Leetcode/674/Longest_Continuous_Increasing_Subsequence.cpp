class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res=0;
        int pre=INT_MIN;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>pre) count++;
            else count=1;
            pre=nums[i];
            res=max(res, count);
        }
        return res;
    }
};
