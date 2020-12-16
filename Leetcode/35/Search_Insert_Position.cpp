class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<end){
            mid=(end+start)/2;
            if(target==nums.at(mid)) return mid;
            else if(target>nums.at(mid)){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        mid=(end+start)/2;
        if(target>nums.at(mid)) return mid+1;
        else return mid;
         
    }
};
