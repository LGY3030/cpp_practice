//Solution 1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) nums1.swap(nums2);
        unordered_set<int> uset;
        unordered_set<int> tmp;
        vector<int> res;
        for(auto & i:nums2) uset.insert(i);
        for(auto & i:nums1){
            if(uset.find(i)!=uset.end()) tmp.insert(i);
        }
        for(auto &i:tmp) res.push_back(i);
        return res;
    }
};


//Solution 2
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset;
        vector<int> res;
        for(auto &i:nums1) uset.insert(i);
        for(auto &i:nums2){
            if(uset.count(i)){
                res.push_back(i);
                uset.erase(i);
            }
        }
        return res;
    }
};
