//Solution 1
class Solution {
public:
    int jump(vector<int>& nums) {
        int last=nums.size()-1;
        int res=0;
        while(last!=0){
            int temp=last;
            for(int i=last-1; i>=0; i--){
                if(i+nums[i]>=last) temp=i;
            }
            last=temp;
            res++;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0;
        int maxjump=0;
        int next=0;
        int i=0;
        while(next<nums.size()-1){
            maxjump=max(maxjump, i+nums[i]);
            if(i==next){
                next=maxjump;
                res++;
            }
            i++;
        }
        return res;
    }
};
