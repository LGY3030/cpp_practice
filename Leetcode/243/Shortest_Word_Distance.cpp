//Solution 1
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int slow=-1;
        int fast=-1;
        int res=INT_MAX;
        for(int i=0; i<wordsDict.size(); i++){
            if(wordsDict[i]==word1 || wordsDict[i]==word2){
                if(slow==-1) slow=i;
                else if(fast==-1) fast=i;
                else{
                    if(fast<slow) fast=i;
                    else slow=i;
                }
                if(fast!=-1 && slow!=-1 && wordsDict[fast]!=wordsDict[slow]){
                    res=min(res, abs(fast-slow));
                }
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int slow=-1;
        int fast=-1;
        int res=INT_MAX;
        for(int i=0; i<wordsDict.size(); i++){
            if(wordsDict[i]==word1 || wordsDict[i]==word2){
                if(slow==-1) slow=i;
                else if(fast==-1) fast=i;
                else{
                    if(fast<slow) fast=i;
                    else slow=i;
                }
                if(fast!=-1 && slow!=-1 && wordsDict[fast]!=wordsDict[slow]){
                    res=min(res, abs(fast-slow));
                    if(res==1) return 1;
                }
            }
        }
        return res;
    }
};
