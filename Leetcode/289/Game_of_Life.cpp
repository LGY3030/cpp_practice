class Solution {
public:
    //0->1:2, 1->0:3
    vector<pair<int, int>> vec={{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                int count=0;
                for(auto&v:vec){
                    int x=i+v.first;
                    int y=j+v.second;
                    if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && (board[x][y]==1 || board[x][y]==3)) count++;
                }
                if(board[i][j]==0 && count==3) board[i][j]=2;
                if(board[i][j]==1 && (count<2 || count>3)) board[i][j]=3;
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==2) board[i][j]=1;
                if(board[i][j]==3) board[i][j]=0;
            }
        }
    }
};
