//Solution 1 
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

//Solution 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0;
        int second = nums.size()-1;
        while(second>=first){
            int mid=(first+second)/2;
            if(nums[mid]<target) first=mid+1;
            else second=mid-1;
        }
        return first==-1? 0:first;
    }
};
