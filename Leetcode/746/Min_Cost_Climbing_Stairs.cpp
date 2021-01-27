//Solution 1
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> vec;
        vec.push_back(cost[0]);
        vec.push_back(cost[1]);
        for(int i=2;i<cost.size();i++){
            int tmp=min(vec[i-1],vec[i-2]);
            vec.push_back(cost[i]+tmp);
        }
        return min(vec[vec.size()-1],vec[vec.size()-2]);
    }
};


//Solution 2
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first=cost[0];
        int second=cost[1];
        for(int i=2;i<cost.size();i++){
            int tmp=min(first,second);
            first=second;
            second=tmp+cost[i];
        }
        return min(first,second);
    }
};
