//Solution 1
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==1) return true;
        int flag=0;
        if(word[0]-'a'>=0) flag=1;
        else{
            if(word[1]-'a'>=0) flag=2;
            else flag=3;
        }
        for(int i=1; i<word.length(); i++){
            if(flag==1 && word[i]-'a'<0) return false;
            if(flag==2 && word[i]-'a'<0) return false;
            if(flag==3 && word[i]-'a'>=0) return false;
        }
        return true;
    }
};

//Solution 2
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()<2) return true;
        int flag=0;
        if(word[0]-'a'<0){
            if(word[1]-'a'<0) flag=1;
        }
        for(int i=1;i<word.length();i++){
            if(flag==1){
                if(word[i]-'a'>=0) return false;
            }
            else{
                if(word[i]-'a'<0) return false;
            }
        }
        return true;
    }
};
