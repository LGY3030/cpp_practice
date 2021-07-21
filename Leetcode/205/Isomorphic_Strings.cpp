//Solution 1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap;
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end()){
                if(umap[s[i]] != t[i]) return false;
            }
            else{
                for(auto get:umap){
                    if(get.second == t[i]) return false;
                }
                umap[s[i]] = t[i];
            }
        }
        return true;
    }
};

//Solution 2
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> umap_s;
        unordered_map<char, int> umap_t;
        string for_s="";
        string for_t="";
        int count_s=0;
        int count_t=0;
        for(int i=0; i<s.length(); i++){
            if(umap_s.find(s[i])!=umap_s.end()) for_s+=(umap_s[s[i]]+'a');
            else{
                umap_s[s[i]]=count_s;
                count_s++;
            }
            if(umap_t.find(t[i])!=umap_t.end()) for_t+=(umap_t[t[i]]+'a');
            else{
                umap_t[t[i]]=count_t;
                count_t++;
            }
        }
        return for_s==for_t;
    }
};
