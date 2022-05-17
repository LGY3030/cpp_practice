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

//Solution 3
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int flag = -1;
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) < nums.size()){
                if(nums[abs(nums[i])] == 0) flag = abs(nums[i]);
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(flag == i) continue;
            if(nums[i] > 0 || (flag == -1 && nums[i] == 0)) return i;
        }
        return nums.size();
    }
};
