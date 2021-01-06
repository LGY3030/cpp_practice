class Solution {
public:
    int getnum(int &n){
        int res=0;
        while(n!=0){
            res+=(n%10)*(n%10);
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> uset;
        int origin = n;
        while(origin!=1){
            if(uset.find(origin)!=uset.end()) break;
            uset.insert(origin);
            origin = getnum(origin);
        }
        if(origin!=1) return false;
        return true;
    }
};
