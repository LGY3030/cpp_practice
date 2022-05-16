class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res=0;
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i]==0) res+=customers[i];
        }
        int maxcount=0;
        int count=0;
        for(int i=0; i<minutes; i++){
            if(grumpy[i]==1) count+=customers[i];
        }
        maxcount=count;
        int idx=0;
        for(int i=minutes; i<customers.size(); i++){
            if(grumpy[idx]==1) count-=customers[idx];
            if(grumpy[i]==1) count+=customers[i];
            maxcount=max(maxcount, count);
            idx++;
        }
        return res+maxcount;
    }
};
