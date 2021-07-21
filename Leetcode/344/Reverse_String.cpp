//Solution 1
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++){
            char tmp = s.at(i);
            s.at(i) = s.at(s.size()-1-i);
            s.at(s.size()-1-i) = tmp;
        }
    }
};

//Solution 2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(j>i){
            char temp=s[i];
            s[i++]=s[j];
            s[j--]=temp;
        }
    }
};
