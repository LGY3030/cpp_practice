//Solution 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        auto cmp = [](vector<int> a, vector<int> b){
            return a[0]<b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>end){
                res.push_back({start, end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else if(intervals[i][1]>end){
                end=intervals[i][1];
            }
            if(i==intervals.size()-1) res.push_back({start, end});
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(res.back()[1]<intervals[i][0]) res.push_back(intervals[i]);
            else res.back()[1]=max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        auto cmp=[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(res.back()[1]<intervals[i][0]) res.push_back(intervals[i]);
            else res.back()[1]=max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};
