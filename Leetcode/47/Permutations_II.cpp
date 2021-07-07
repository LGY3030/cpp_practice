//Solution 1
class Solution {
private:
    void help(vector<vector<int>> &res, vector<int>& nums, unordered_map<int, int> &umap, vector<int> vec){
        if(vec.size()==nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(umap[nums[i]]<=0 || (i!=0 && nums[i-1]==nums[i])) continue;
            vec.push_back(nums[i]);
            umap[nums[i]]--;
            help(res, nums, umap, vec);
            umap[nums[i]]++;
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> umap;
        for(auto&i:nums) umap[i]++;
        sort(nums.begin(), nums.end());
        help(res, nums, umap, {});
        return res;
    }
};

//Solution 2
class Solution {
private:
    void bk(vector<vector<int>>& res, vector<int>& nums, vector<int> vec){
        if(vec.size()==nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==-11 || (i>0 && nums[i]==nums[i-1])) continue;
            int temp=nums[i];
            vec.push_back(nums[i]);
            nums[i]=-11;
            bk(res, nums, vec);
            vec.pop_back();
            nums[i]=temp;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        bk(res, nums, {});
        return res;
    }
};
