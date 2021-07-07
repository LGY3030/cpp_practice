//Solution 1
class Solution {
private:
    void help(vector<vector<int>> &res, vector<int>& nums, vector<int> vec, vector<int> tmp){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vec[i]++==0){
                tmp.push_back(nums[i]);
                help(res, nums, vec, tmp);
                tmp.pop_back();
                vec[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec(nums.size());
        help(res, nums, vec, {});
        return res;
    }
};

//Solution 2
class Solution {
private:
    void help(vector<vector<int>> &res, vector<int>& nums, vector<int> tmp){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-11){
                int temp=nums[i];
                tmp.push_back(nums[i]);
                nums[i]=-11;
                help(res, nums, tmp);
                tmp.pop_back();
                nums[i]=temp;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        help(res, nums, {});
        return res;
    }
};

//Solution 3
class Solution {
private:
    void help(vector<vector<int>> &res, vector<int>& nums, int begin){
        if(begin==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[i], nums[begin]);
            help(res, nums, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        help(res, nums, 0);
        return res;
    }
};
