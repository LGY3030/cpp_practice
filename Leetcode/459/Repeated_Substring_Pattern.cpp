//Solution 1
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length()<2) return false;
        for(int i=1; i<=s.length()/2; i++){
            string tmp=s.substr(0,i);
            if(s.length()%tmp.length()!=0) continue;
            int flag=0;
            for(int j=i; j<=s.length()-tmp.length() ; j+=tmp.length()){
                if(s.substr(j,tmp.length())!=tmp){
                    flag=1;
                    break;
                } 
            }
            if(flag==1) continue;
            return true;
        }
        return false;
    }
};


//Solution 2
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp=s+s;
        temp=temp.substr(1, 2*s.length()-2);
        if(temp.find(s)!=string::npos) return true; //or != -1
        return false;
    }
};
