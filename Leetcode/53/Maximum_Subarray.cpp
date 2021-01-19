//Solution 1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp=nums[0];
        int res=tmp;
        for(int i=1;i<nums.size();i++){
            tmp=max(nums[i], nums[i]+tmp);
            res=max(res,tmp);
        }
        return res;
    }
};
