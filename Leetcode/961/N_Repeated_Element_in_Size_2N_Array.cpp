class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> uset;
        for(auto &i:A){
            if(uset.count(i)) return i;
            uset.insert(i);
        }
        return 0;
    }
};
