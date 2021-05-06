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
