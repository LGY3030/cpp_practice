//Solution 1
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<int, int> umap;
        vector<pair<int, int>> vec;
        for(auto&i:s) umap[i]++;
        for(auto&i:umap) vec.push_back(i);
        sort(vec.begin(), vec.end(), cmp);
        string res="";
        for(auto&i:vec){
            for(int j=0;j<i.second;j++){
                char tmp=i.first;
                res+=tmp;
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for(auto&i:s) umap[i]++;
        auto cmp = [&umap](char a, char b){
            return (umap[a]>umap[b] || (umap[a]==umap[b]&&a>b));
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
