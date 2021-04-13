class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        vector<int> vec(n+1, INT_MAX);
        vec[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                vec[i]=min(vec[i], vec[i-j*j]+1);
            }
        }
        return vec[n];
    }
};
