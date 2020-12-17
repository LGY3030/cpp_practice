//Solution 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        int res = 0;
        for(auto i: nums){
            if(umap.find(i)!=umap.end()){
                umap[i] = 1;
            }
            else{
                umap[i] = 0;
            }
        }
        for(auto i:umap){
            if(i.second==0) res = i.first;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=nums.at(0);
        for(int i=1; i<nums.size();i++){
            res^=nums.at(i);
        }
        return res;
    }
};
