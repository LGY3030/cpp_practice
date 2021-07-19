//Solution 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        int count=strs[0].length();
        for(auto&i:strs){
            if(i.length()<count) count=i.length();
        }
        
        string res="";
        for(int i=0, z=0;i<count && z==0;i++){
            char tmp=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(tmp!=strs[j][i]){
                    z=1;
                    break;
                }
                if(j==strs.size()-1) res+=tmp;
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        sort(strs.begin(), strs.end());
        string first=strs[0];
        string end=strs[strs.size()-1];
        string res="";
        for(int i=0;i<first.length()||i<end.length();i++){
            if(first[i]==end[i]) res+=first[i];
            else break;
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string start=strs[0];
        string end=strs[strs.size()-1];
        int count=0;
        for(int i=0; i<start.length(); i++){
            if(start[i]==end[i]) count++;
            else break;
        }
        return start.substr(0, count);
    }
};
