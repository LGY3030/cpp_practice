//Solution 1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> vec(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for(int i=0; i<obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1) break;
            vec[0][i]=1;
        }
        for(int i=0; i<obstacleGrid.size(); i++){
            if(obstacleGrid[i][0]==1) break;
            vec[i][0]=1;
        }
        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=1; j<obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j]==1) vec[i][j]=0;
                else vec[i][j]=vec[i-1][j]+vec[i][j-1];
            }
        }
        return vec[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

//Solution 2
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int vec[obstacleGrid.size()][obstacleGrid[0].size()];
        //vector<vector<int>> vec(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for(int i=0; i<obstacleGrid.size(); i++){
            for(int j=0; j<obstacleGrid[0].size(); j++){
                vec[i][j]=0;
            }
        }
        for(int i=0; i<obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1) break;
            vec[0][i]=1;
        }
        for(int i=0; i<obstacleGrid.size(); i++){
            if(obstacleGrid[i][0]==1) break;
            vec[i][0]=1;
        }
        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=1; j<obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j]==1) vec[i][j]=0;
                else vec[i][j]=vec[i-1][j]+vec[i][j-1];
            }
        }
        return vec[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
