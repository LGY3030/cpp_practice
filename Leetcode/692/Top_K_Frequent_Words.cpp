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
