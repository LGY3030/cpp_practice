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

//Solution 2
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

//Solution 3
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for(auto&i:s) umap[i]++;
        int count=0;
        for(auto&i:t){
            if(umap.find(i)==umap.end()) return false;
            else if(umap[i]==0) return false;
            else umap[i]--;
            count++;
        }
        if(count!=s.length()) return false;
        return true;
    }
};

//Solution 4
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for(auto&i:s) umap[i]++;
        for(auto&i:t){
            if(umap.find(i)==umap.end()) return false;
            else if(umap[i]==0) return false;
            else umap[i]--;
        }
        return true;
    }
};
