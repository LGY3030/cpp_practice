//Solution 1, Recursive, time exceeded
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};


//Solution 2, loop
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int first=1;
        int second=2;
        for(int i=3;i<=n;i++){
            int tmp=first+second;
            first=second;
            second=tmp;
        }
        return second;
    }
};
