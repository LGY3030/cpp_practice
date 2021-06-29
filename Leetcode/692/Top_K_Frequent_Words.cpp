//Solution 1
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for(auto i:words) umap[i]++;
        vector<pair<string, int>> vec;
        for(auto i:umap) vec.push_back(make_pair(i.first, i.second));
        auto cmp=[](pair<string, int> x, pair<string, int> y){ 
            if(x.second!=y.second) return x.second>y.second; 
            return x.first<y.first;
        };
        sort(vec.begin(), vec.end(), cmp);
        vector<string> res;
        for(int i=0;i<k;i++) res.push_back(vec[i].first);
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for(auto&i:words) umap[i]++;
        
        auto cmp=[](pair<string, int> a, pair<string, int> b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        
        for(auto&i:umap) pq.push({i.first, i.second});
        vector<string> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    struct cmp{
        bool operator()(pair<string, int> a, pair<string, int> b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for(auto&i:words) umap[i]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for(auto&i:umap){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        vector<string> res(k--);
        while(!pq.empty()){
            res[k--]=pq.top().first;
            pq.pop();
        }
        return res;
    }
};

//Solution 4
class Solution {
public:
    struct cmp{
        bool operator()(pair<string, int> a, pair<string, int> b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for(auto&i:words) umap[i]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for(auto&i:umap){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        vector<string> res(k--);
        while(!pq.empty()){
            res[k--]=pq.top().first;
            pq.pop();
        }
        return res;
    }
};
