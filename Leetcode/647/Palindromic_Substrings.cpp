//Solution 1
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0; i<s.length()*2-1; i++){
            int pre;
            int pos;
            if(i%2==0){
                res++;
                pre=i/2-1;
                pos=i/2+1;
            }
            else{
                pre=i/2;
                pos=i/2+1;
            } 
            while(pre>=0 && pos<s.length()){
                if(s[pre--]==s[pos++]) res++;
                else break;
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> vec(s.length(), vector<int>(s.length()));
        int res=0;
        for(int i=0;i<s.length();i++){
            vec[i][i]=1;
            res++;
        }
        for(int right=1;right<s.length();right++){
            for(int left=0;left<right;left++){
                if(s[right]==s[left] && (left+1==right || vec[left+1][right-1]==1)){
                    vec[left][right]=1;
                    res++;
                }
            }
        }
        return res;
    }
};
