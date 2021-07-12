//Solution 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i:nums){
            if(umap.find(i)!=umap.end()) return true;
            else umap[i] = 0;
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(auto&i:nums){
            if(uset.find(i)!=uset.end()) return true;
            uset.insert(i);
        }
        return false;
    }
};

//Solution 3
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};
