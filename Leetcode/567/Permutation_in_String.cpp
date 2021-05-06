//Solution 1
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        vector<int> fors1(26);
        vector<int> fors2(26);
        for(auto&i:s1) fors1[i-'a']++;
        int slow=0;
        for(int i=0;i<s2.length();i++){
            if(i<s1.length()) fors2[s2[i]-'a']++;
            else{
                fors2[s2[i]-'a']++;
                fors2[s2[slow]-'a']--;
                slow++;
            }
            if(fors1==fors2) return true;
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        vector<int> vec(26);
        for(auto&i:s1) vec[i-'a']++;
        int count=s1.length();
        int slow=0;
        for(int i=0; i<s2.length(); i++){
            if(vec[s2[i]-'a']-->0) count--;
            if(count==0) return true;
            if(i-slow+1==s1.length() && vec[s2[slow++]-'a']++>=0) count++;
        }
        return false;
    }
};
