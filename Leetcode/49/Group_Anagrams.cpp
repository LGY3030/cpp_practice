//Solution 1, Time Exceeded, O(n^3)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> count(strs.size());
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            if(count.at(i)!=0) continue;
            unordered_map<char, int> umap,tmp;
            for(int j=0;j<strs[i].length();j++){
                umap[strs[i][j]]++;
            }
            tmp=umap;
            vector<string> vecs;
            for(int j=i;j<strs.size();j++){
                umap=tmp;
                int flag=0;
                for(int k=0;k<strs[j].length();k++){
                    if(umap.find(strs[j][k])==umap.end()){
                        flag=1;
                        break;
                    }
                    umap[strs[j][k]]--;
                }
                for(auto l:umap){
                    if(l.second!=0){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    count[j]=1;
                    vecs.push_back(strs[j]);
                }
            }
            res.push_back(vecs);
        }
        return res;
    }
};


//Solution 2, O(n^2)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> copy=strs;
        vector<int> count(strs.size());
        for(auto &i:strs){
            sort(i.begin(), i.end());
        }
        for(int i=0;i<strs.size();i++){
            if(count.at(i)!=0) continue;
            vector<string> vec;
            for(int j=i;j<strs.size();j++){
                if(count.at(j)!=0) continue;
                if(strs.at(j)==strs.at(i)){
                    vec.push_back(copy.at(j));
                    count.at(j)=1;
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};


//Solution 3, unordered_map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> res;
        for(auto &i:strs){
            string tmp=i;
            sort(i.begin(), i.end());
            umap[i].push_back(tmp);
        }
        for(auto &i:umap) res.push_back(i.second);
        return res;
    }
};
