class TrieNode{
    public:
        bool is_end;
        vector<TrieNode*> children;
        TrieNode(){
            is_end=false;
            children=vector<TrieNode*>(26, nullptr);
        }
};
class Trie{
     public:
        Trie(vector<string>& words){
            root=new TrieNode();
            for(int i=0; i<words.size(); i++){
                addWord(words[i]);
            }
        }
        void addWord(string& str){
            TrieNode* temp=root;
            for(int i=0; i<str.length(); i++){
                if(temp->children[str[i]-'a']==nullptr) temp->children[str[i]-'a']=new TrieNode();
                temp=temp->children[str[i]-'a'];
            }
            temp->is_end=true;
        }
        TrieNode* getroot(){
            return root;
        } 
    private:
        TrieNode* root;
};
class Solution {
private:
    void help(vector<vector<char>>& board, int row, int column, unordered_set<string>& res, TrieNode* root, string word){
        if(row<0 || row>=board.size() || column<0 || column>=board[0].size() || board[row][column]==' ') return;
        if(root->children[board[row][column]-'a']!=nullptr){
            word=word+board[row][column];
            root=root->children[board[row][column]-'a'];
            if(root->is_end) res.insert(word);
            char temp = board[row][column];
            board[row][column]=' ';
            help(board, row+1, column, res, root, word);
            help(board, row-1, column, res, root, word);
            help(board, row, column+1, res, root, word);
            help(board, row, column-1, res, root, word);
            board[row][column]=temp;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        unordered_set<string> uset;
        Trie* trie=new Trie(words);
        TrieNode* root=trie->getroot();
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                help(board, i, j, uset, root, "");
            }
        }
        for(auto&i: uset)res.push_back(i);
        return res;
    }
};
