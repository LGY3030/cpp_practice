class Solution {
private:
    bool ispalin(string s){
        if(s.length()==0) return false;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i]) return false;
        }
        return true;
    }
    void help(vector<vector<string>> &res, string s, vector<string> vec){
        if(s=="") res.push_back(vec);   
        for(int i=0;i<s.length();i++){
            if(ispalin(s.substr(0, i+1))){
                vec.push_back(s.substr(0, i+1));
                help(res, s.substr(i+1), vec);
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        help(res, s, {});
        return res;
    }
};
