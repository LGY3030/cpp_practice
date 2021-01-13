//Solution 1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first=-1;
        int second=-1;
        for(int i=nums.size()-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(j>first){
                        first=j;
                        second=i;
                    }
                }
            }
            
        }
        if(first==-1) sort(nums.begin(), nums.end());
        else{
            int tmp=nums[first];
            nums[first]=nums[second];
            nums[second]=tmp;
            sort(nums.begin()+first+1, nums.end());
        }
    }
};


//Solution 2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                first=i-1;
                break;
            }
        }
        if(first==-1){
            sort(nums.begin(), nums.end());
            return;
        }
        for(int i=nums.size()-1;i>first;i--){
            if(nums[i]>nums[first]){
                int tmp=nums[first];
                nums[first]=nums[i];
                nums[i]=tmp;
                sort(nums.begin()+first+1, nums.end());
            }
        }
    }
};

