class Solution {
private:
    void form(int n, int last, vector<string>& res, string str){
        if(n==0){
            for(int i=0;i<last;i++) str+=")";
            res.push_back(str);
            return;
        }
        if(n==last) form(n-1, last, res, str+"(");
        else{
            form(n, last-1, res, str+")");
            form(n-1, last, res, str+"(");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        form(n, n, res, "");
        return res;
    }
};
