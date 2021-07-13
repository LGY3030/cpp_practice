//Solution 1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<pair<int, int>> sta;
        sta.push(make_pair(nums2[nums2.size()-1], -1));
        for(int i=nums2.size()-2;i>=0;i--){
            while(!sta.empty()){
                if(sta.top().first<=nums2[i]){
                    if(sta.top().second==-1){
                        umap[sta.top().first]=-1;
                        sta.top().first=nums2[i];
                        break;
                    }
                    else{
                        umap[sta.top().first]=sta.top().second;
                        sta.pop();
                    }
                }
                else{
                    sta.push(make_pair(nums2[i], sta.top().first));
                    break;
                }
            }
        }
        while(!sta.empty()){
            umap[sta.top().first]=sta.top().second;
            sta.pop();
        }
        vector<int> res;
        for(auto &i: nums1){
            res.push_back(umap[i]);
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> sta;
        for(auto &i:nums2){
            while(sta.size()>0 && sta.top()<i){
                umap[sta.top()]=i;
                sta.pop();
            }
            sta.push(i);
        }
        vector<int> res;
        for(auto &i:nums1){
            res.push_back(umap.count(i)>=1? umap[i]: -1);
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<nums1.size(); i++){
            int flag=0;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]) flag=1;
                if(flag && nums2[j]>nums1[i]){
                    nums1[i]=nums2[j];
                    break;
                } 
                if(j==nums2.size()-1) nums1[i]=-1;
            }
        }
        return nums1;
    }
};
