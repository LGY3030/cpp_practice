//Solution 1
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> umap;
        for(int i=0; i<numbers.size(); i++){
            umap[target-numbers[i]] = i+1;
        }
        for(int i=0; i<numbers.size(); i++){
            if(umap.find(numbers[i])!=umap.end() && i!=umap[numbers[i]]) return {i+1, umap[numbers[i]]};
        }
        return {-1, -1};
    }
};

//Solution 2
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while(right>left){
            int sum=numbers[left]+numbers[right];
            if(sum==target) return {left+1, right+1};
            if(sum<target) left++;
            else right--;
        }
        return {-1, -1};
    }
};
