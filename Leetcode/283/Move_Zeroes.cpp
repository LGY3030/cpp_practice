//Solution 1, use extra memory
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> bnew;
        int num=0;
        for(auto i:nums){
            if(i==0) num++;
            else bnew.push_back(i);
        }
        for(int i=0;i<num;i++) bnew.push_back(0);
        nums=bnew;
    }
};


//Solution 2, two for loop
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)!=0) continue;
            for(int j=i+1;j<nums.size();j++){
                if(nums.at(j)==0) continue;
                int tmp=nums.at(i);
                nums.at(i)=nums.at(j);
                nums.at(j)=tmp;
                break;
            }
        }
    }
};


//Solution 3, replace original vector and use count to memorize the number of non-zero number
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(auto i:nums){
            if(i!=0){
                nums.at(count) = i;
                count++;
            }
        }
        for(int i =count;i<nums.size();i++){
            nums.at(i)=0;
        }
    }
};


//Solution 4, two pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)!=0 && nums.at(slow)==0){
                int tmp=nums.at(i);
                nums.at(i)=nums.at(slow);
                nums.at(slow)=tmp;
            }
            if(nums.at(slow)!=0) slow++;
        }

    }
};

