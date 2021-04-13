//Solution 1 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int first=0;
        int second=0;
        vector<vector<int>> res;
        while(first<firstList.size() && second<secondList.size()){
            if(firstList[first][0]<secondList[second][0]){
                if(firstList[first][1]>=secondList[second][0]){
                    if(firstList[first][1]>secondList[second][1]){
                        res.push_back({secondList[second][0], secondList[second][1]});
                        second++;
                    }
                    else{
                        res.push_back({secondList[second][0], firstList[first][1]});
                        first++;
                    }
                }
                else first++;
            }
            else{
                if(firstList[first][0]<=secondList[second][1]){
                    if(firstList[first][1]>secondList[second][1]){
                        res.push_back({firstList[first][0], secondList[second][1]});
                        second++;
                    }
                    else{
                        res.push_back({firstList[first][0], firstList[first][1]});
                        first++;
                    }
                }
                else second++;
            }
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for(int i=0, j=0; i<firstList.size() && j<secondList.size(); ){
            if(firstList[i][1]<secondList[j][0]) i++;
            else if(firstList[i][0]>secondList[j][1]) j++;
            else{
                res.push_back({ max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
                if(firstList[i][1]<secondList[j][1]) i++;
                else j++;
            }
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for(int i=0, j=0; i<firstList.size() && j<secondList.size(); firstList[i][1]<secondList[j][1]? i++:j++){
            int m=max(firstList[i][0], secondList[j][0]);
            int n=min(firstList[i][1], secondList[j][1]);
            if(m<=n) res.push_back({m,n});
        }
        return res;
    }
};
