//Solution 1
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> vec(n, INT_MAX);
        vector<bool> flag(n, false);
        vec[k-1] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            flag[temp.second-1] = true;
            for(auto&i:times){
                if(temp.second==i[0] && !flag[i[1]-1] && temp.first+i[2]<vec[i[1]-1]){
                    vec[i[1]-1] = temp.first+i[2];
                    pq.push({temp.first+i[2], i[1]});
                }
            }
        }
        int res = -1;
        for(int i=0; i<vec.size(); i++){
            if(flag[i]==false) return -1;
            if(vec[i]>res) res=vec[i];
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> destination(n, INT_MAX);
        vector<bool> arrived(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            if(arrived[pq.top().second-1]==false){
                pair<int, int> temp=pq.top();
                pq.pop();
                arrived[temp.second-1]=true;
                destination[temp.second-1]=min(destination[temp.second-1], temp.first);
                for(int i=0; i<times.size(); i++){
                    if(times[i][0]==temp.second) pq.push({destination[temp.second-1]+times[i][2], times[i][1]});
                }
            }
            else pq.pop();
        }
        int res=0;
        for(auto&i:destination){
            if(i==INT_MAX) return -1;
            res=max(res, i);
        }
        return res;
    }
};
