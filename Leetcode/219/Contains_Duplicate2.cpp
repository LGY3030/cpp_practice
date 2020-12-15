class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++){
            if(umap.find(nums.at(i))!=umap.end()){
                if(i-umap[nums.at(i)]<=k) return true;
                else{
                    umap[nums.at(i)] = i;
                }
            }
            else{
                umap[nums.at(i)] = i;
            }
        }
        return false;
    }
};
