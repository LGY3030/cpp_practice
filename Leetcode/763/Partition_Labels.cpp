//Solution 1
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> last(26);
        int slow=0;
        int fast=0;
        int maxnum=INT_MIN;
        for(int i=0;i<S.length();i++) last[S[i]-'a']=i;
        while(fast<S.length()){
            if(last[S[fast]-'a']>maxnum) maxnum=last[S[fast]-'a'];
            if(fast==maxnum){
                res.push_back(fast-slow+1);
                slow=fast+1;
            }
            fast++;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> umap;
        for(int i=0; i<s.length(); i++){
            umap[s[i]]=i;
        }
        int count=0;
        int most=0;
        vector<int> res;
        for(int i=0; i<s.length(); i++){
            count++;
            most=max(most, umap[s[i]]);
            if(most==i){
                res.push_back(count);
                count=0;
            }
        }
        if(count) res.push_back(count);
        return res;
    }
};
