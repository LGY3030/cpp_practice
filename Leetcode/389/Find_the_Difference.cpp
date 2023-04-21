//Solution 1
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> umap;
        for(auto&i:t) umap[i]++;
        for(auto&i:s) umap[i]--;
        for(auto&i:umap){
            if(i.second!=0) return i.first;
        }
        return 'a';
    }
};


//Solution 2
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;
        for(auto&i:t) res+=i;
        for(auto&i:s) res-=i;
        return res;
    }
};


//Solution 3
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;
        for(int i=0;i<s.length();i++){
            res=res^s[i]^t[i];
        }
        res^=t[t.length()-1];
        return res;
    }
};

//Solution 4
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < s.length(); i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[t.length() - 1];
    }
};
