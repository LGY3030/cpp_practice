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

//Solution 3
class Solution {
private:
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second;
        }  
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int &k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<vector<int>> res;
        for(auto&i:points){
            if(pq.size()<k) pq.push({i[0], i[1]});
            else if(pq.top().first*pq.top().first+pq.top().second*pq.top().second>i[0]*i[0]+i[1]*i[1]){
                pq.push({i[0], i[1]});
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};
