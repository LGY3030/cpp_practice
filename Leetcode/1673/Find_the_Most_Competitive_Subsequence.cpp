//Solution 1
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            return a.first>b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<=nums.size()-k; i++) pq.push({nums[i], i});
        
        vector<int> res;
        res.push_back(pq.top().first);
        int idx=pq.top().second;
        pq.pop();
        for(int i=nums.size()-k+1; i<nums.size(); i++){
            pq.push({nums[i], i});
            while(pq.top().second<idx) pq.pop();
            res.push_back(pq.top().first);
            idx=pq.top().second;
            pq.pop();
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> sta;
        int count = nums.size()-k;
        for(int i=0; i<nums.size(); i++){
            while(count && !sta.empty() && nums[i]<sta.top() ){
                sta.pop();
                count--;
            }
            sta.push(nums[i]);
        }
        while(count){
            sta.pop();
            count--;
        }
        vector<int> res(k);
        for(int i=k-1; i>=0; i--){
            res[i]=sta.top();
            sta.pop();
        }
        return res;
    }
};
