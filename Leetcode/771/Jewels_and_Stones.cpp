class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> uset;
        int res=0;
        for(auto i:jewels) uset.insert(i);
        for(auto i:stones){
            if(uset.count(i)) res++;
        }
        return res;
    }
};
