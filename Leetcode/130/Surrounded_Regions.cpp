class Solution {
public:
    vector<pair<int, int>> vec={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, int row, int column){
        if(row<0 || row>=board.size() || column<0 || column>=board[0].size() || board[row][column]=='*' || board[row][column]=='X') return;
        board[row][column]='*';
        for(auto&v:vec) dfs(board, row+v.first, column+v.second);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1)){
                    dfs(board, i, j);
                }
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='*') board[i][j]='O';
            }
        }
    }
};
