//Solution 1
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();
        vector<int> vec(26);
        for(auto&i:s) vec[i-'a']++;
        int idx=0;
        while(idx <s.size() && vec[s[idx]-'a'] >= k) idx++;
        if(idx == s.size()) return s.size();
        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx+1) , k);
        
        return max(left, right);
    }
};


//Solution 2
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k>s.length()) return 0;
        vector<int> vec(26);
        for(auto&i:s) vec[i-'a']++;
        
        int start=0;
        int end=s.length()-1;
        while(start<s.length() && vec[s[start]-'a']<k) start++;
        while(end>=0 && vec[s[end]-'a']<k) end--;
        if(end<start) return 0;
        s=s.substr(start, end-start+1);
        
        int idx=0;
        while(idx<s.size() && vec[s[idx]-'a']>=k) idx++;
        if(idx==s.size()) return s.size();
        int left=longestSubstring(s.substr(0,idx), k);
        int right=longestSubstring(s.substr(idx+1), k);
        return max(left, right);
    }
};
