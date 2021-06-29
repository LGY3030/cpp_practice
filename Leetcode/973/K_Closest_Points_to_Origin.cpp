//Solution 1
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto cmp=[](vector<int> a, vector<int> b){
            return a[0]*a[0]+a[1]*a[1]>b[0]*b[0]+b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(auto&i: points) pq.push(i);
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() == k){
            return points;
        }
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            return a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto&i: points){
            pq.push({i[0], i[1]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};
