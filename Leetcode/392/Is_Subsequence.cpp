//Solution 1
class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char> que;
        for(auto&i:s) que.push(i);
        for(auto&i:t){
            if(i==que.front()) que.pop();
        }
        if(que.size()==0) return true;
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> vec(s.length()+1, vector<int> (t.length()+1, 0));
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=t.length(); j++){
                if(s[i-1]==t[j-1]) vec[i][j]=vec[i-1][j-1]+1;
                else vec[i][j]=max(vec[i-1][j], vec[i][j-1]);
            }
        }
        if(vec[s.length()][t.length()]==s.length()) return true;
        return false;
    }
};
