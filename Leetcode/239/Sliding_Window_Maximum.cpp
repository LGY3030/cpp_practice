class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        for(int i=k; i<=nums.size(); i++){
            while(pq.top().second<i-k) pq.pop();
            res.push_back(pq.top().first);
            if(i<nums.size()) pq.push({nums[i], i});
        }
        return res;
    }
};
