class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> umap;
        int res=0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                int tmp=nums[i]*nums[j];
                res=res+8*umap[tmp];
                umap[tmp]++;
            }
        }
        return res;
    }
};
