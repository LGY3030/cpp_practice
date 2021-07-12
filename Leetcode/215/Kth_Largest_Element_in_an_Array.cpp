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

//Solution 3
class Solution {
private:
    struct cmp{
      bool operator()(int a, int b){
          return a>b;
      }  
    };
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        for(auto&i:nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
