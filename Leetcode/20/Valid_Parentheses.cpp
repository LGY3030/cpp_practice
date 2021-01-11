class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1) return false;
        stack<char> sta;
        for(auto&i:s){
            if(i=='(' || i=='[' || i=='{') sta.push(i);
            else{
                if(sta.size()==0) return false;
                if(sta.top()=='(' && i!=')') return false;
                if(sta.top()=='{' && i!='}') return false;
                if(sta.top()=='[' && i!=']') return false;
                sta.pop();
            }
        }
        if(sta.size()!=0) return false;
        return true;
    }
};
