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
