//Solution 1
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> vec(26);
        for(auto&i:S) vec[i-'a']++;
        for(auto&i:vec){
            if(i>S.length()/2+S.length()%2) return "";
        }
        string res="A";
        int idx=-1;
        for(int i=0;i<S.length();i++){
            int count=0;
            for(int j=0;j<26;j++){
                if(vec[j]>count && res[res.length()-1]-'a'!=j){
                    count=vec[j];
                    idx=j;
                }
            }
            res+=char(idx+'a');
            vec[idx]--;
        }
        return res.substr(1);
    }
};

//Solution 2
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> vec(26);
        int max=0;
        for(auto&i:S){
            if(++vec[i-'a']>vec[max]) max=i-'a';
        }
        if(vec[max]*2-1>S.length()) return "";
        int i=0;
        while(vec[max]){
            S[i]=char(max+'a');
            vec[max]--;
            i=i+2;
        }
        for(int j=0;j<26;j++){
            while(vec[j]){
                if(i>=S.length()) i=1;
                S[i]=char(j+'a');
                i+=2;
                vec[j]--;
            }
        }
        return S;
    }
};
