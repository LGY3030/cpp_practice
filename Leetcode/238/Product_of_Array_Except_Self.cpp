//Solution 1, Time Exceeded
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<=1) return {};
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            int tmp=1;
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                tmp*=nums[j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};


//Solution 2, with division, error because of division by zero
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<=1) return {};
        vector<int> res;
        int tmp=1;
        for(auto&i:nums) tmp*=i;
        for(int i=0;i<nums.size();i++){
            tmp/=nums[i];
            res.push_back(tmp);
            tmp*=nums[i];
        }
        return res;
    }
};


//Solution 3, space O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size);
        vector<int> first(size, 1);
        vector<int> last(size, 1);
        
        for(int i=1;i<size;i++){
            first[i]=first[i-1]*nums[i-1];
            last[size-i-1]=last[size-i]*nums[size-i];
        }

        for(int i=0;i<size;i++){
            res[i]=first[i]*last[i];
        }
        
        return res;
    }
};


//Solution 4, space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size,1);
        for(int i=1;i<size;i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int tmp=1;
        for(int i=size-2;i>=0;i--){
            tmp=tmp*nums[i+1];
            res[i]=res[i]*tmp;
        }
        return res;
    }
};


//Solution 5, leetcode discussion solution(more concise)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
        }
        
        for(int i=n-1;i>=0;i--)
        {
            res[i]*=fromLast;
            fromLast*=nums[i];
        }
        return res;
    }
};
