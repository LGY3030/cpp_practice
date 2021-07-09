class Solution {
private:
    void help(vector<vector<int>> &res, vector<int>& nums, vector<int> vec, int idx){
        res.push_back(vec);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue; 
            vec.push_back(nums[i]);
            help(res, nums, vec, i+1);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        help(res, nums, {}, 0);
        return res;
    }
};
