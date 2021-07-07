class Solution {
private:
    void help(vector<vector<int>> &res, vector<int>& nums, int idx, vector<int> vec){
        res.push_back(vec);
        for(int i=idx; i<nums.size(); i++){
            vec.push_back(nums[i]);
            help(res, nums, i+1, vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        help(res, nums, 0, {});
        return res;
    }
};
