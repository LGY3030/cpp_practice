//Solution 1
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

//Solution 2
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++){
            if(umap.find(nums[i])!=umap.end() && abs(umap[nums[i]]-i)<=k) return true;
            umap[nums[i]]=i;
        }
        return false;
    }
};

//Solution 3
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;
        for(int i=0; i<nums.size(); i++){
            if(i>k) uset.erase(nums[i-k-1]);
            if(!uset.insert(nums[i]).second) return true;
        }
        return false;
    }
};
