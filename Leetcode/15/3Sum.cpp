class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int tmp=-nums[i];
            int front=i+1;
            int end=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(front<end){
                int sum=nums[front]+nums[end];
                if(sum>tmp) end--;
                else if(sum<tmp) front++;
                else{
                    vector<int> vec={nums[i], nums[front], nums[end]};
                    res.push_back(vec);
                    front++;
                    end--;
                    while(front<end){
                        if(nums[front]==vec[1]) front++;
                        else if(nums[end]==vec[2]) end--;
                        else break;
                    }
                }
            }
        }
        return res;
    }
};
