//Solution 1, Slow
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(abs(sum-target)<abs(res-target)) res=sum;
                }
            }
        }
        return res;
    }
};



//Solution 2
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int front=i+1;
            int end=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(front<end){
                int sum=nums[i]+nums[front]+nums[end];
                if(abs(res-target)>abs(sum-target)) res = sum;
                if(sum<target) front++;
                else if(sum>target) end--;
                else return target;
            }
        }
        return res;
    }
};
