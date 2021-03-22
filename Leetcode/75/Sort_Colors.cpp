//Solution 1 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto cmp = [](int a, int b){
            return a<b;
        };
        sort(nums.begin(), nums.end(), cmp);
    }
};

//Solution 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==1) mid++;
            else if(nums[mid]==0){
                int temp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=temp;
                low++;
                mid++;
            }
            else{
                int temp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=temp;
                high--;
            }
        }
    }
};
