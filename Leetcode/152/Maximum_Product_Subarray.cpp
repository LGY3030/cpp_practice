class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int res=INT_MIN;
        int maxnum=1;
        int minnum=1;
        for(auto&i:nums){
            if(i<0){
                int temp=maxnum;
                maxnum=minnum;
                minnum=temp;
            }
            maxnum=max(maxnum*i, i);
            minnum=min(minnum*i, i);
            res=max(res, maxnum);
        }
        return res;
    }
};
