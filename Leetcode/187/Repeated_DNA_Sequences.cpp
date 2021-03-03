class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<11) return {};
        unordered_set<string> uset;
        unordered_set<string> tmp;
        vector<string> res;
        for(int i=0;i<s.length()-9;i++){
            if(uset.count(s.substr(i,10))) tmp.insert(s.substr(i,10));
            else uset.insert(s.substr(i,10));
        }
        for(auto&i:tmp) res.push_back(i);
        return res;
    }
};
