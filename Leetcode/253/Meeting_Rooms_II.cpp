class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for(int i=0; i<intervals.size(); i++){
            m[intervals[i][0]]++;
            m[intervals[i][1]]--;
        }
        int res=0;
        int count=0;
        for(auto&i:m){
            count+=i.second;
            res=max(res, count);
        }
        return res;
    }
};
