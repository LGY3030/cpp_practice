//Solution 1
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<char> sta;
        if(S.length()==2) return 1;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(') sta.push('(');
            else{
                sta.pop();
                if(sta.empty()){
                    if(i==S.length()-1){
                        return 2*scoreOfParentheses(S.substr(1, S.length()-2));
                    }
                    else{
                        return scoreOfParentheses(S.substr(0, i+1))+scoreOfParentheses(S.substr(i+1));
                    }
                }
            }
        }
        return 0;
    }
};

//Solution 2
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> sta;
        sta.push(0);
        for(int i=0; i<S.length(); i++){
            if(S[i]=='(') sta.push(0);
            else{
                int temp=sta.top();
                sta.pop();
                if(temp==0) sta.top()+=1;
                else sta.top()+=temp*2;
            }
        }
        return sta.top();
    }
};

//Solution 3
class Solution {
public:
    int scoreOfParentheses(string S) {
        int level=0;
        int res=0;
        for(int i=0;i<S.length()-1;i++){
            if(S[i]=='('){
                if(S[i+1]==')') res+=1<<level;
                level++;
            }
            else level--;
        }
        return res;
    }
};
