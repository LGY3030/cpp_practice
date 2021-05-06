class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0;
        int count=0;
        int slow=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;
            while(count>k){
                if(nums[slow++]==0) count--;
            }
            res=max(res, i-slow+1);
        }
        return res;
    }
};
