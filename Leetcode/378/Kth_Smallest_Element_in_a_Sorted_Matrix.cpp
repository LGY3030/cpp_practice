//Solution 1
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp=[](int a, int b){
            return a>b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto&i:matrix){
            for(auto&j:i) pq.push(j);
        }
        for(int i=0; i<k-1; i++) pq.pop();
        return pq.top();
    }
};

//Solution 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp=[](int a, int b){
            return a<b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto&i:matrix){
            for(auto&j:i){
                pq.push(j);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};
