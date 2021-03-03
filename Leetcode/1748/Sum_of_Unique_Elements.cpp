//Solution 1 
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;
        int res=0;
        for(auto&i:nums) umap[i]++;
        for(auto&i:umap){
            if(i.second==1) res+=i.first;
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;
        int res=0;
        for(auto&i:nums){
            if(umap[i]==0) res+=i;
            else if(umap[i]==1) res-=i;
            umap[i]++;
        }
        return res;
    }
};
