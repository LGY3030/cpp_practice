//Solution 1
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

//Solution 2
class Solution {
private:
    void bk(vector<string>& res, int& n, int left, int right, string temp){
        if(left==n && right==n){
            res.push_back(temp);
            return;
        }
        if(left<n) bk(res, n, left+1, right, temp+'(');
        if(right<left) bk(res, n, left, right+1, temp+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bk(res, n, 0, 0, "");
        return res;
    }
};
