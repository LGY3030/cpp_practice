//Solution 1
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end()){
                umap[s[i]]=-1;
            }
            else{
                umap[s[i]]=i;
            }
        }
        int result=s.length()+1;
        for(auto i:umap){
            if(i.second!=-1){
                if(i.second<result){
                    result = i.second;
                }
            }
        }
        if(result==s.length()+1) return -1;
        return result;
    }
};


//Solution 2
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto &c : s) {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};


//Solution 3
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26);
        for(auto &i: s){
            vec.at(i-'a')++;
        }
        for(int i=0;i<s.length();i++){
            if(vec.at(s[i]-'a')==1) return i;
        }
        return -1;
    }
};

//Solution 4
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> umap;
        for(int i = 0; i < s.length(); i++){
            umap[s[i]].push_back(i);
        }
        int res = INT_MAX;
        for(auto each: umap){
            if(each.second.size() == 1){
                res = min(res, each.second[0]);
            }
        }
        return res == INT_MAX? -1:res;
    }
};
