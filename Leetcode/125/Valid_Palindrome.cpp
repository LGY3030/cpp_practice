//Solution 1, use ascii code
class Solution {
public:
    bool isPalindrome(string s) {
        string get="";
        for(auto &i:s){
            if((65<=i&&i<=90)||(48<=i&&i<=57)) get+=i;
            if(97<=i&&i<=122) get+=i-32;
        }
        for(int i=0;i<(get.length())/2;i++){
            if(get[i]!=get[get.length()-i-1]) return false;
        }
        return true;
    }
};



//Solution 2, use isalnum and tolower toupper functions
class Solution {
public:
    bool isPalindrome(string s) {
        int first=0, second=s.length()-1;
        while(first<second){
            while(first<second && !isalnum(s[first])) first++;
            while(first<second && !isalnum(s[second])) second--;
            if(tolower(s[first])!=tolower(s[second])) return false;
            first++;
            second--;
        }
        return true;
    }
};
