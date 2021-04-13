class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int res=0;
        int slow=0;
        int product=1;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            while(slow<=i && product>=k){
                product/=nums[slow++];
            }
            res+=i-slow+1;
        }
        return res;
    }
};
