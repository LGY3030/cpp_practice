//Solution 1
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto&i:words){
            vector<int> map(26);
            vector<int> check(26);
            for(int j=0;j<i.length();j++){
                if(map[pattern[j]-'a']==0 && check[i[j]-'a']==0){
                    map[pattern[j]-'a']=i[j];
                    check[i[j]-'a']++;
                }
                else if(map[pattern[j]-'a']!=i[j]) break;
                
                if(j==i.length()-1) res.push_back(i);
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
private:
    string helper(string s){
        unordered_map<char, int> umap;
        for(int i=0;i<s.length();i++){
            if(!umap.count(s[i])) umap[s[i]]=umap.size();
            s[i]=char('a'+umap[s[i]]);
        }
        return s;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto&i:words){
            if(helper(pattern)==helper(i)) res.push_back(i);
        }
        return res;
    }
};
