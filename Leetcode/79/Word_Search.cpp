//Solution 1
class Solution {
private:
    bool help(vector<vector<char>>& board, string word, int i, int j){
        if(word=="") return true;
        vector<pair<int, int>> tvec = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto&k:tvec){
            if((i+k.first>=0 && i+k.first<board.size()) && (j+k.second>=0 && j+k.second<board[i].size())){
                if(board[i+k.first][j+k.second]==word[0]){
                    char tmp=board[i+k.first][j+k.second];
                    board[i+k.first][j+k.second]='0';
                    if(help(board, word.substr(1), i+k.first, j+k.second)) return true;
                    board[i+k.first][j+k.second]=tmp;
                }
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]==word[0]){
                    char tmp=board[i][j];
                    board[i][j]='0';
                    if(help(board, word.substr(1), i, j)) return true;
                    board[i][j]=tmp;
                }
            }
        }
        return false;
    }
};


//Solution 2
class Solution {
private:
    bool help(vector<vector<char>>& board, string word, int start, int end){
        if(word=="") return true;
        if(start<0 || start>board.size()-1 || end<0 || end>board[0].size()-1 || board[start][end]!=word[0]) return false;
        char tmp=board[start][end];
        board[start][end]='*';
        if(help(board, word.substr(1), start+1, end) || help(board, word.substr(1), start-1, end) || help(board, word.substr(1), start, end+1) || help(board, word.substr(1), start, end-1)) return true;
        board[start][end]=tmp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(help(board, word, i, j)) return true;
            }
        }
        return false;
    }
};

//Solution 3
class Solution {
private:
    int m, n;
    bool help(vector<vector<char>>& board, string& word, int start, int end, int idx){
        if(idx==word.length()) return true;
        if(start<0 || start>m-1 || end<0 || end>n-1 || board[start][end]=='*' || board[start][end]!=word[idx]) return false;
        char tmp=board[start][end];
        board[start][end]='*';
        if(help(board, word, start+1, end, idx+1) || help(board, word, start-1, end, idx+1) || help(board, word, start, end+1, idx+1) || help(board, word, start, end-1, idx+1)) return true;
        board[start][end]=tmp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(help(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
