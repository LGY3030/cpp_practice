class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0;
        int slow=0;
        int count=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                odd++;
                if(odd>=k){
                    count=1;
                    while(nums[slow++]%2==0) count++;
                    res+=count;
                }
            }
            else if(odd>=k){
                res+=count;
            }
        }
        return res;
    }
};
