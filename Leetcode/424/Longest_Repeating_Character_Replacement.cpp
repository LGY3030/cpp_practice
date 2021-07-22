//Solution 1
class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0;
        int thismax=0;
        int res=0;
        vector<int> vec(26);
        for(int i=0;i<s.length();i++){
            vec[s[i]-'A']++;
            if(vec[s[i]-'A']>thismax) thismax=vec[s[i]-'A'];
            while(i-start+1-thismax>k){
                vec[s[start]-'A']--;
                start++;
                thismax=0;
                for(int j=0;j<26;j++){
                    if(thismax<vec[j]) thismax=vec[j];
                }
            }
            res=max(res, i-start+1);
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int characterReplacement(string s, int k) {
        int same=0;
        int start=0;
        int end=0;
        vector<int> vec(26);
        while(end<s.length()){
            same=max(same, ++vec[s[end++]-'A']);
            if(end-start-same>k) --vec[s[start++]-'A'];
        }
        return end-start;
    }
};
