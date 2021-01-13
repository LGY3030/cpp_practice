class Solution {
public:
    string convert(string s, int numRows) {
        //if(s.length()<2) return s;
        vector<string> vec(numRows);
        string res="";
        int temp=2*numRows-2;
        if(temp==0) temp=1;
        for(int i=0;i<s.length();i++){
            int tmp=i%(temp);
            if(tmp>=numRows) tmp=2*numRows-2-tmp;
            vec[tmp]+=s[i];
        }
        for(auto&i:vec) res+=i;
        return res;
    }
};
