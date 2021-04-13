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
