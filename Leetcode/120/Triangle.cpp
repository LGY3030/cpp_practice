//Solution 1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1; i<triangle.size(); i++){
            for(int j=0; j<triangle[i].size(); j++){
                int left=INT_MAX;
                int right=INT_MAX;
                if(j-1>=0) left=triangle[i-1][j-1];
                if(j<triangle[i-1].size()) right=triangle[i-1][j];
                if(left<right) triangle[i][j] += left; 
                else triangle[i][j] += right;
            }
        }
        int res = INT_MAX;
        for(auto&i:triangle[triangle.size()-1]){
            if(i<res) res=i;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res(triangle.size());
        for(int i=0; i<triangle.size(); i++){
            res[i] = triangle[triangle.size()-1][i];
        }
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                if(res[j]>res[j+1]) res[j]=triangle[i][j]+res[j+1];
                else res[j]=triangle[i][j]+res[j];
            }
        }
        return res[0];
    }
};
