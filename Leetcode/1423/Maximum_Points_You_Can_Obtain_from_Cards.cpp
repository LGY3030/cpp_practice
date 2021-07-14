//Solution 1
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int slow=0;
        int fast=cardPoints.size()-1;
        int res=0;
        int tmp1=0;
        int tmp2=0;
        for(int i=slow;i<=k+slow-1;i++) tmp1+=cardPoints[i];
        for(int i=fast;i>=fast-k+1;i--) tmp2+=cardPoints[i];
        while(k>0){
            if(tmp1<tmp2){
                tmp2-=cardPoints[fast];
                tmp1-=cardPoints[k+slow-1];
                res+=cardPoints[fast--];
            }
            else{
                tmp1-=cardPoints[slow];
                tmp2-=cardPoints[fast-k+1];
                res+=cardPoints[slow++];
            }
            k--;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int slow=cardPoints.size()-k;
        int fast=cardPoints.size()-1;
        int res=0;
        for(int i=slow;i<=fast;i++){
            res+=cardPoints[i];
        }
        if(slow==0) return res;
        int tmp=res;
        while(slow<cardPoints.size()){
            tmp-=cardPoints[slow++];
            fast++;
            tmp+=cardPoints[fast%cardPoints.size()];
            res=max(res,tmp);
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res=0;
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        res=sum;
        for(int i=k-1; i>=0; i--){
            sum-=cardPoints[i];
            sum+=cardPoints[cardPoints.size()+i-k];
            res=max(res, sum);
        }
        return res;
    }
};
