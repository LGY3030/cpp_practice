//Solution 1
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> uset;
        for(auto &i:A){
            if(uset.count(i)) return i;
            uset.insert(i);
        }
        return 0;
    }
};

//Solution 2
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[(nums.size()+i-1)%nums.size()]==nums[i] || nums[(nums.size()+i-2)%nums.size()]==nums[i]) return nums[i];
        }
        return -1;
    }
};
