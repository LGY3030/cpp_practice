//Solution 1
class Solution {
	public:
	    vector<int> twoSum(vector<int>& nums, int target) {
	        bool flag = true;
	        vector<int> res;
	        for(int i=0; i<nums.size()-1 && flag; i++){
	            for(int j=i+1; j<nums.size() && flag; j++){
	                if(nums.at(i)+nums.at(j) == target){
	                    res = {i,j};
	                    flag = false;
	                }
	            }
	        }
	        return res;
	    }
};


//Solution 2
class Solution {
	public:
	    vector<int> twoSum(vector<int>& nums, int target) {
	        unordered_map<int, int> umap;
	        vector<int> res;
	        for(int i = 0; i<nums.size(); i++){
	            if(umap.find(target-nums.at(i)) != umap.end()){
	                res = {umap.at(target-nums.at(i)), i};
	            }
	            else{
	                umap[nums.at(i)] = i;
	            }
	        }
	        return res;
	    }
};
