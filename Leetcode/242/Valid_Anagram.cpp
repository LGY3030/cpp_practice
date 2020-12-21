//Solution 1, hashtable
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end()) umap[s[i]]++;
            else umap[s[i]]=1;
        }
        for(int i=0;i<t.length();i++){
            if(umap.find(t[i])==umap.end()) return false;
            umap[t[i]]--;
        }
        for(auto i:umap){
            if(i.second!=0) return false;
        }
        return true;
    }
};

//Solution 2, use array to simulate hash table

//Solution 3, use sort and check if two string are equal
