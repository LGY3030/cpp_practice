//Solution 1, time exceeded
class Solution {
private:
    bool help(vector<int>& nums, int idx){
        if(idx==nums.size()-1) return true;
        bool res=false;
        for(int i=1; i<=nums[idx]; i++){
            res=res||help(nums, idx+i);
        }
        return res;
    }
public:
    bool canJump(vector<int>& nums) {
        return help(nums, 0);
    }
};

//Solution 2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1;
        for(int i=nums.size()-2; i>=0; i--){
            if(i+nums[i]>=last) last=i;
        }
        return last==0;
    }
};
