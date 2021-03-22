/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //Solution 1
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        vector<pair<int, vector<int>>> vec;
        queue<pair<TreeNode*, int>> sta;
        unordered_map<int, vector<int>> umap;
        sta.push(make_pair(root, 0));
        while(!sta.empty()){
            pair<TreeNode*, int> tmp;
            tmp=sta.front();
            sta.pop();
            umap[tmp.second].push_back(tmp.first->val);
            if(tmp.first->left!=nullptr) sta.push(make_pair(tmp.first->left, tmp.second+1));
            if(tmp.first->right!=nullptr) sta.push(make_pair(tmp.first->right, tmp.second+1));
            
        }
        for(auto &i:umap) vec.push_back(i);
        auto cmp=[](pair<int, vector<int>> a, pair<int, vector<int>> b){
          return a.first>b.first;  
        };
        sort(vec.begin(), vec.end(), cmp);
        for(auto &i:vec) res.push_back(i.second);
        return res;
    }
};


//Solution 2
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        while(que.size()>0){
            pair<TreeNode*, int> tmp=que.front();
            que.pop();
            if(tmp.second>=res.size()) res.push_back({});
            res[tmp.second].push_back(tmp.first->val);
            if(tmp.first->left) que.push(make_pair(tmp.first->left, tmp.second+1));
            if(tmp.first->right) que.push(make_pair(tmp.first->right, tmp.second+1));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//Solution 3
class Solution {
private:
    void dfs(TreeNode * root, vector<vector<int>> &res, int level){
        if(root==nullptr) return;
        if(level>=res.size()) res.push_back({});
        res[level].push_back(root->val);
        dfs(root->left, res, level+1);
        dfs(root->right, res, level+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        dfs(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

//Solution 4, no reverse
class Solution {
private:
    int getdepth(TreeNode * root){
        if(root==nullptr) return 0;
        return max(getdepth(root->left), getdepth(root->right))+1;
    }
    void dfs(TreeNode * root, vector<vector<int>> &res, int level){
        if(root==nullptr) return;
        res[level].push_back(root->val);
        dfs(root->left, res, level-1);
        dfs(root->right, res, level-1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        int depth=getdepth(root);
        vector<vector<int>> res(depth);
        dfs(root, res, depth-1);
        return res;
    }
};

