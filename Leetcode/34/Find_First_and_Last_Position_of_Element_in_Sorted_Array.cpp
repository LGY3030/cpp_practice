class Solution {
private:
    int help(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=nums.size();
        while(end>=start){
            int mid=start+(end-start)/2;
            if(target<=nums[mid]){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=help(nums, target);
        int end=help(nums, target+1)-1;
        if(end>=start) return {start, end};
        else return {-1, -1};
    }
};
