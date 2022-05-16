class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int idx=0;
        while(idx<intervals.size() && intervals[idx][1]<newInterval[0]){
            res.push_back(intervals[idx++]);
        }
        int start=newInterval[0];
        int end=newInterval[1];
        while(idx<intervals.size() && end>=intervals[idx][0]){
            start=min(start, intervals[idx][0]);
            end=max(end, intervals[idx][1]);
            idx++;
        }
        res.push_back({start, end});
        while(idx<intervals.size()){
            res.push_back(intervals[idx++]);
        }
        return res;
    }
};
