class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> vec(s.size(), vector<int>(s.size(), 0));
        int res=1;
        for(int i=0; i<s.size(); i++){
            vec[i][i]=1;
        }
        for(int i=s.size()-2; i>=0; i--){
            for(int j=i+1; j<s.size(); j++){
                if(j==i+1 && s[j]==s[j-1]) vec[i][j]=2;
                else{
                    if(s[j]==s[i]) vec[i][j]=2+vec[i+1][j-1];
                    else vec[i][j]=max(vec[i+1][j], vec[i][j-1]);
                }
                res=max(res, vec[i][j]);
            }
        }
        return res;
    }
};
