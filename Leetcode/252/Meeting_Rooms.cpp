class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto cmp=[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<intervals[i-1][1]) return false;
        }
        return true;
    }
};
