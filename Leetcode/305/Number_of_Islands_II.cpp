//Solution 1, Time Exceeded
class Solution {
private:
    void dfs(vector<vector<int>>& vec, int i, int j){
        if(i<0 || i>=vec.size() || j<0 || j>=vec[0].size() || vec[i][j]!=1) return;
        vec[i][j]=2;
        dfs(vec, i-1, j);
        dfs(vec, i, j+1);
        dfs(vec, i+1, j);
        dfs(vec, i, j-1);
    }
    int getnum(vector<vector<int>> vec){
        int res=0;
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[0].size(); j++){
                if(vec[i][j]==1){
                    res++;
                    dfs(vec, i, j);
                }
            }
        }
        return res;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        if(m==0 && n==0) return {};
        vector<int> res;
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for(auto&i:positions){
            vec[i[0]][i[1]]=1;
            res.push_back(getnum(vec));
        }
        return res;
    }
};

//Solution 2, time exceeded
class Solution {
private:
    vector<pair<int, int>> dir={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& vec, int i, int j){
        stack<pair<int, int>> sta;
        sta.push({i, j});
        while(!sta.empty()){
            auto temp=sta.top();
            sta.pop();
            vec[temp.first][temp.second]=2;
            for(auto&i:dir){
                if(temp.first+i.first>=0 && temp.first+i.first<vec.size() && temp.second+i.second>=0 && temp.second+i.second<vec[0].size() && vec[temp.first+i.first][temp.second+i.second]==1) sta.push({temp.first+i.first, temp.second+i.second});
            }
        }
    }
    int getnum(vector<vector<int>> vec){
        int res=0;
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[0].size(); j++){
                if(vec[i][j]==1){
                    res++;
                    dfs(vec, i, j);
                }
            }
        }
        return res;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        if(m==0 && n==0) return {};
        vector<int> res;
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for(auto&i:positions){
            vec[i[0]][i[1]]=1;
            res.push_back(getnum(vec));
        }
        return res;
    }
};

//Solution 3
class Solution {
private:
    vector<pair<int, int>> dir={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<int> par;
    int find(int num){
        while(num!=par[num]){
            num=par[par[num]];
            //num=par[num];
        }
        return num;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        par=vector<int>(m*n, -1);
        int count=0;
        for(auto&i:positions){
            int x=i[0];
            int y=i[1];
            int oldpos=x*n+y;
            if(par[oldpos]!=-1){
                res.push_back(count);
                continue;
            }
            par[oldpos]=oldpos;
            count++;
            for(auto&j:dir){
                int row=x+j.first;
                int col=y+j.second;
                int newpos=row*n+col;
                if(row>=0 && row<m && col>=0 && col<n && par[newpos]!=-1){
                    int oldfind=find(oldpos);
                    int newfind=find(newpos);
                    if(oldfind!=newfind){
                        par[oldfind]=newfind;
                        count--;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};




