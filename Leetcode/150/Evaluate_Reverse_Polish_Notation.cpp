class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto&i:tokens){
            if(isdigit(i[i.size()-1])) stk.push(stoi(i));
            else{
                int temp2=stk.top();
                stk.pop();
                int temp1=stk.top();
                stk.pop();
                if(i=="-") stk.push(temp1-temp2);
                if(i=="+") stk.push(temp1+temp2);
                if(i=="*") stk.push(temp1*temp2);
                if(i=="/") stk.push(temp1/temp2);
            }
        }
        return stk.top();
    }
};
