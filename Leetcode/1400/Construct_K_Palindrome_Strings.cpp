class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        if(s.size()==k) return true;
        unordered_map<char, int> umap;
        for(auto&i:s) umap[i]++;
        int count=0;
        for(auto&i:umap){
            if(i.second%2==1) count++;
        }
        if(count<=k) return true;
        return false;
    }
};
