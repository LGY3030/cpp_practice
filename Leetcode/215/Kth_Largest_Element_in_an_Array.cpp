//Solution 1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp=[](int a, int b){
            return a<b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto&i:nums) pq.push(i);
        for(int i=0;i<k-1;i++) pq.pop();
        return pq.top();
    }
};

//Solution 2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp=[](int a, int b){
            return a>b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto&i:nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
