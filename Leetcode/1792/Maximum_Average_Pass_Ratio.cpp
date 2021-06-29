class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            double tmp1=1.0*a.first/a.second;
            double tmp2=1.0*b.first/b.second;
            return ((1.0*(a.first+1)/(a.second+1))-tmp1) < ((1.0*(b.first+1)/(b.second+1))-tmp2);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        double res=0;
        for(auto&i:classes){
            res+=(1.0*i[0]/i[1]);
            pq.push({i[0], i[1]});
        }
        for(int i=0;i<extraStudents;i++){
            pair<int, int> tmp = pq.top();
            pq.pop();
            res-=(1.0*tmp.first/tmp.second);
            tmp.first+=1;
            tmp.second+=1;
            res+=(1.0*tmp.first/tmp.second);
            pq.push(tmp);
        }
        return res/classes.size();
    }
};
