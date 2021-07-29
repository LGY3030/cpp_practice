//Solution 1
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

//Solution 2
class Solution {
private:
    bool help(int n, unordered_set<int>& uset){
        if(uset.count(n)){
            if(n==1) return true;
            return false;
        }
        else uset.insert(n);
        int temp=0;
        while(n){
            temp+=(n%10)*(n%10);
            n/=10;
        }
        return help(temp, uset);
    }
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        return help(n, uset);
    }
};
