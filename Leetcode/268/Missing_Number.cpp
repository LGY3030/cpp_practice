//Solution 1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        for(int i=0; i<nums.size(); i++){
            while(nums[i]!=i && nums[i]!=-1){
                int temp=nums[i];
                nums[i]=nums[temp];
                nums[temp]=temp;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==-1) return i;
        }
        return -1;
    }
};

//Solution 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        for(int i=0; i<nums.size(); i++){
            res=res^(i+1)^nums[i];
        }
        return res;
    }
};
