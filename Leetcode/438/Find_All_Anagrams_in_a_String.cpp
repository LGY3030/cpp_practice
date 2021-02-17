//Solution 1
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return vector<int>();
        
        vector<int> vec(26);
        vector<int> tmp(26);
        vector<int> res;
        for(auto&i:p) vec[i-'a']++;
        int slow=0;
        int fast=p.length()-1;
        for(int i=slow;i<=fast;i++){
            tmp[s[i]-'a']++;
        }
        while(true){
            if(tmp==vec) res.push_back(slow);
            fast++;
            slow++;
            if(fast==s.length()) break;
            tmp[s[slow-1]-'a']--;
            tmp[s[fast]-'a']++;
        }
        return res;
    }
};


//Solution 2, Concise
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return {};
        vector<int> vec(26), tmp(26), res;
        for(auto&i:p) vec[i-'a']++;
        for(int i=0;i<s.length();i++){
            tmp[s[i]-'a']++;
            if(i>=p.length()) tmp[s[i-p.length()]-'a']--;
            if(tmp==vec) res.push_back(i-p.length()+1);
        }
        return res;
    }
};
