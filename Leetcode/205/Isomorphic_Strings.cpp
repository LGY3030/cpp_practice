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
