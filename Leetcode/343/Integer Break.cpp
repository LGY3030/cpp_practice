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
