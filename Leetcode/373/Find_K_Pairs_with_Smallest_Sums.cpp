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

//Solution 3
class Solution {
private:
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first+a.second<b.first+b.second;
        }  
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i=0; i<min((int)nums1.size(), k); i++){
            for(int j=0; j<min((int)nums2.size(), k); j++){
                if(pq.size()<k) pq.push({nums1[i], nums2[j]});
                else if(nums1[i]+nums2[j]<pq.top().first+pq.top().second){
                    pq.push({nums1[i], nums2[j]});
                    pq.pop();
                }
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

//Solution 4
class Solution {
private:
    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.first + a.second < b.first + b.second;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto i: nums1){
            for(auto j: nums2){
                if(pq.size() == k && i + j > pq.top().first + pq.top().second) break;
                pq.push({i, j});
                if(pq.size() > k) pq.pop();
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
