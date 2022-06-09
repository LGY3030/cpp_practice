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

//Solution 3
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> vec(s.length(), vector<bool>(s.length(), false));
        for(int i=0; i<s.length(); i++){
            vec[i][i] = true;
        }
        string res="";
        res+=s[0];
        for(int i=s.length()-2; i>=0; i--){
            for(int j=i+1; j<s.length(); j++){
                if(j==i+1 || vec[i+1][j-1]){
                    if(s[i] == s[j]){
                        vec[i][j]=true;
                        if(j-i+1>res.length()) res=s.substr(i, j-i+1);
                    }
                }
            }
        }
        return res;
    }
};

//Solution 4
class Solution {
private:
    string getSub(string & s, int start, int end){
        while(s[start] == s[end] && start > 0 && end < s.length() - 1){
            start--;
            end++;
        }
        if(s[start] != s[end]) return s.substr(start + 1, end - start - 1);
        return s.substr(start, end - start + 1);
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.length() * 2 - 1; i++){
            string tmp = "";
            if(i % 2) tmp = getSub(s, i / 2, i / 2 + 1);
            else tmp = getSub(s, i / 2, i / 2);
            
            if(tmp.length() > res.length()) res = tmp;
        }
        return res;
    }
};
