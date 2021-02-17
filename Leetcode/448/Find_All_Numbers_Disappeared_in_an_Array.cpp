//Solution 1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size()<=1) return nums;
        vector<int> vec(nums.size());
        vector<int> res;
        for(auto&i:nums) vec[i-1]++;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==0) res.push_back(i+1);
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size()<=1) return nums;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1] = (nums[abs(nums[i])-1]>0)? -nums[abs(nums[i])-1] : nums[abs(nums[i])-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};
