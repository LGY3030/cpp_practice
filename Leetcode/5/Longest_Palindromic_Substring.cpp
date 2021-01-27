//Solution 1, Time Exceeded
class Solution {
public:
    string longestPalindrome(string s) {
        int max=0;
        int first=0;
        int second=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                int flag=0;
                for(int k=i;k<=(i+j)/2;k++){
                    if(s[k]!=s[j-k+i]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0 && j-i+1>max){
                    first=i;
                    second=j;
                    max=j-i+1;
                }
            }
        }
        string res="";
        for(int i=first;i<=second;i++) res=res+s[i];
        return res;
    }
};


//Solution 2
class Solution {
public:
    string longestPalindrome(string s) {
        int max=0;
        int first=0;
        int second=0;
        for(int i=0;i<2*s.length()-1;i++){
            if(i%2==0){
                int count=0;
                while(i/2-count>=0 && i/2+count<=s.length()-1){
                    if(s[i/2-count]!=s[i/2+count]) break;
                    count++;
                }
                count--;
                if(2*count+1>max){
                    first=i/2-count;
                    second=i/2+count;
                    max=2*count+1;
                }
            }
            else{
                int count=0;
                while(i/2-count+1>=0 && i/2+count<=s.length()-1){
                    if(s[i/2-count+1]!=s[i/2+count]) break;
                    count++;
                }
                count--;
                if(2*count>max){
                    first=i/2-count+1;
                    second=i/2+count;
                    max=2*count;
                }
            }
        }
        string res="";
        for(int i=first;i<=second;i++) res+=s[i];
        return res;
    }
};
