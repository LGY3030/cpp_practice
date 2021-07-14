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

//Solution 3
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        unordered_map<char, int> umap;
        int count=1;
        for(int i=0; i<pattern.size(); i++){
            if(umap.find(pattern[i])==umap.end()) umap[pattern[i]]=count++;
            pattern[i]=umap[pattern[i]];
        }
        for(auto&word:words){
            string i=word;
            if(i.size()!=pattern.size()) continue;
            umap={};
            count=1;
            for(int j=0; j<i.size(); j++){
                if(umap.find(i[j])==umap.end()) umap[i[j]]=count++;
                i[j]=umap[i[j]];
                if(i[j]!=pattern[j]) break;
            }
            if(i==pattern) res.push_back(word);
        }
        return res;
    }
};
