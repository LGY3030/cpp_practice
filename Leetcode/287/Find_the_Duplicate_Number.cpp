//Solution 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        int res=0;
        for(auto &i:nums){
            if(uset.find(i)!=uset.end()){
                res=i;
                break;
            }
            uset.insert(i);
        }
        return res;
    }
};


//Solution 2, binary search, binary get val and chech num in the nums which is less that val and decide next part
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start=1;
        int end=nums.size()-1;
        while(start<end){
            int mid=(end+start)/2;
            int count=0;
            for(auto &i:nums){
                if(i<=mid) count++;
            }
            if(count>mid) end=mid;
            else start=mid+1;
        }
        return end;
    }
};
