//Solution 1, time exceeded
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) count++;
                if(sum>k) break;
            }
        }
        return count;
    }
};


//Solution 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int sum=0;
        int res=0;
        for(auto&i:nums){
            sum+=i;
            if(sum==k) res++;
            if(umap.find(sum-k)!=umap.end()) res+=umap[sum-k];
            umap[sum]++;
        }
        return res;
    }
};
