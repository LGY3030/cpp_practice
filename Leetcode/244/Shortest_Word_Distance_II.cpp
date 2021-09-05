//Solution 1, time exceeded
class WordDistance {
private:
    vector<string> vec;
public:
    WordDistance(vector<string>& wordsDict) {
        vec=wordsDict;
    }
    
    int shortest(string word1, string word2) {
        int start=-1;
        int end=-1;
        int res=INT_MAX;
        for(int i=0; i<vec.size(); i++){
            if(vec[i]==word1 || vec[i]==word2){
                if(start==-1) start=i;
                else if(end==-1) end=i;
                else{
                    if(start<end) start=i;
                    else end=i;
                }
            }
            if(start!=-1 && end!=-1 && vec[start]!=vec[end]){
                res=min(res, abs(start-end));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */

//Solution 2
class WordDistance {
private:
    unordered_map<string, vector<int>> umap;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++) umap[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int i=0;
        int j=0;
        int res=INT_MAX;
        while(i<umap[word1].size() && j<umap[word2].size()){
            res=min(res, abs(umap[word1][i]-umap[word2][j]));
            if(umap[word1][i]>umap[word2][j]) j++;
            else i++;
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
