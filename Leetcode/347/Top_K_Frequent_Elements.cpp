//Solution 1
struct twonum{
    int first;
    int second;
};

//sort 的compare function要是普通函式或是class裡的static函式, 所以可以把cmp function 移到class外面或是寫在class裡面然後加static 
bool cmp(twonum a, twonum b){
    return a.second>b.second;
}
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto&i:nums) umap[i]++;
        
        vector<twonum> vec; 
        twonum twon;
        for(auto&i:umap){
            twon.first=i.first;
            twon.second=i.second;
            vec.push_back(twon);
        }
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> res;
        for(int i=0;i<k;i++) res.push_back(vec[i].first);
        return res;
    }
};


//Solution 2
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto&i:nums) umap[i]++;
        
        auto cmp=[](pair<int, int> a, pair<int, int> b){ return a.second<b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for(auto&i:umap) pq.push({i.first, i.second});
        
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto&i:nums) umap[i]++;
        
        auto cmp=[](pair<int, int> a, pair<int, int> b){ return a.second>b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for(auto&i:umap){
            pq.push({i.first, i.second});
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
