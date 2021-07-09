//Solution 1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int now=nums.at(0);
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums.at(i)==now){
                count++;
            }
            else{
                if(count<1){
                    now=nums.at(i);
                    count=1;
                }
                else count--;
            }
        }
        return now;
    }
};

//Solution 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
