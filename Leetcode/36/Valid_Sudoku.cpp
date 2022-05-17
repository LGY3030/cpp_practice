//Solution 1
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int column[9][9]={0};
        int cell[9][9]={0};
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    int k=i/3*3+j/3;
                    if(row[i][num] || column[j][num] || cell[k][num]){
                        return false;
                    }
                    row[i][num] = column[j][num] = cell[k][num] = 1;
                }
            }
        }
        return true;
    }
};


//Solution 2
class Solution {
private:
    bool vertical(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            vector<int> check(9, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(check[board[j][i] - '0' - 1] == 1) return false;
                    check[board[j][i] - '0' - 1] = 1;
                }
            }
        }
        return true;
    }
    bool horizontal(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            vector<int> check(9, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(check[board[i][j] - '0' - 1] == 1) return false;
                    check[board[i][j] - '0' - 1] = 1;
                }
            }
        }
        return true;
    }
    bool rec(vector<vector<char>>& board){
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int idx = i / 3 * 3 + j / 3;
                    if(umap.find(idx) == umap.end()) umap[idx] = vector<int>(9, 0);
                    if(umap[idx][board[i][j] - '0' - 1] == 1) return false;
                    umap[idx][board[i][j] - '0' - 1] = 1;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return vertical(board) && horizontal(board) && rec(board);
    }
};
