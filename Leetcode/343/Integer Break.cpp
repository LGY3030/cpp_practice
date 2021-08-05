//Solution 1
class Solution {
public:
    int integerBreak(int n) {
        int max[n+1];
        for(int i=0; i<n+1; i++){
            max[i]=1;
        }
        for(int i=2; i<n+1; i++){
            int maxrow=1;
            for(int j=i; j>=i/2; j--){
                int temp=max[j];
                if(i!=n && j==i) temp=j;
                if(maxrow<temp*max[i-j]) maxrow=temp*max[i-j];
            }
            max[i]=maxrow;
        }
        return max[n];
    }
};

//Solution 2
class Solution {
public:
    int integerBreak(int n) {
        vector<int> vec(n+1, INT_MIN);
        vec[1]=1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<=i/2; j++){
                if(j==0){
                    if(i==n) continue;
                    vec[i]=max(vec[i], i);
                }
                else vec[i]=max(vec[i], vec[j]*vec[i-j]);
            }
        }
        return vec[n];
    }
};
