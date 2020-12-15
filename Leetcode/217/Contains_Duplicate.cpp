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
