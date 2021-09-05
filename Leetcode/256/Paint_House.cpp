class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for(int i=1; i<costs.size(); i++){
            costs[i][0]+=min(costs[i-1][1], costs[i-1][2]);
            costs[i][1]+=min(costs[i-1][0], costs[i-1][2]);
            costs[i][2]+=min(costs[i-1][0], costs[i-1][1]);
        }
        int res=INT_MAX;
        for(int i=0; i<3; i++){
            res=min(res, costs[costs.size()-1][i]);
        }
        return res;
    }
};
