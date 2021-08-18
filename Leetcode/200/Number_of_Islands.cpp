class Solution {
private:
    vector<pair<int, int>> vec={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void help(vector<vector<char>>& grid, stack<pair<int, int>> sta){
        while(!sta.empty()){
            auto temp=sta.top();
            sta.pop();
            grid[temp.first][temp.second]='2';
            for(auto&i:vec){
                if(temp.first+i.first>=0 && temp.first+i.first<grid.size() && temp.second+i.second>=0 && temp.second+i.second<grid[0].size() && grid[temp.first+i.first][temp.second+i.second]=='1'){
                    sta.push({temp.first+i.first, temp.second+i.second});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        stack<pair<int, int>> sta;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    sta.push({i, j});
                    help(grid, sta);
                    sta.pop();
                    res++;
                }
            }
        }
        return res;
    }
};
