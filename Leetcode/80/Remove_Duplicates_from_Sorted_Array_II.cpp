//Solution 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        int fast=0;
        bool flag=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                if(!flag){
                    slow++;
                    flag=true;
                }
            }
            else{
                slow++;
                flag=false;
            }
            nums[slow]=nums[i];
            
        }
        return slow+1;
    }
};

//Solution 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]==nums[i-count-2]) count++;
            else nums[i-count]=nums[i];
        }
        return nums.size()-count;
    }
};

//Solution 3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        int now=nums[0];
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==now) count++;
            else{
                now=nums[i];
                count=1;
            }
            if(count<=2){
                slow++;
                nums[slow]=now;
            }
        }
        return slow+1;
    }
};
