//Solution 1
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for(auto&str:emails){
            string first="";
            string second="";
            string tmp="";
            int flag=0;
            int flag2=0;
            for(auto&i:str){
                if(i=='@') flag=1;
                else{
                    if(flag==0){
                        if(i=='.') continue;
                        if(i=='+'){
                            flag2=1;
                            continue;
                        }
                        if(flag2==0) first+=i;
                    }
                    else{
                        second+=i;
                    }
                }
            }
            tmp=first+' '+second;
            res.insert(tmp);
        }
        return res.size();
    }
};


//Solution 2, substr and find function
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for(auto&str:emails){
            string tmp="";
            for(auto&i:str){
                if(i=='+' || i=='@')break;
                if(i=='.') continue;
                tmp+=i;
            }
            tmp+=str.substr(str.find('@'));
            res.insert(tmp);
        }
        return res.size();
    }
};
