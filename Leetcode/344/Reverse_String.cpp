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
