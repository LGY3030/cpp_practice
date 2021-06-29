//Solution 1
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            return a.first+a.second>b.first+b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto& i:nums1){
            for(auto& j:nums2){
                pq.push({i, j});
            }
        }
        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            if(pq.empty()) break;
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            return a.first+a.second<b.first+b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto& i:nums1){
            for(auto& j:nums2){
                pq.push({i, j});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};
