class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            if(i!=0 && nums[i]<=nums[i-1]){
                sum=0;
            }
            sum+=nums[i];
            res=max(res, sum);
        }
        return res;
    }
};
