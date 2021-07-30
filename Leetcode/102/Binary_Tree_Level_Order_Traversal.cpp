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
 //Solution 1, two queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int> > vec;
        vector<int> res;
        queue<TreeNode*> quf;
        queue<TreeNode*> qus;
        quf.push(root);
        while(quf.size()!=0){
            TreeNode* cur=quf.front();
            if(cur->left!=nullptr) qus.push(cur->left);
            if(cur->right!=nullptr) qus.push(cur->right);
            res.push_back(cur->val);
            quf.pop();
            if(quf.size()==0){
                quf.swap(qus);
                vec.push_back(res);
                res={};
                
            }
        }
        return vec;
    }
};


//Solution 2, one queue and a count
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int> > vec;
        vector<int> res;
        queue<TreeNode*> quf;
        quf.push(root);
        int count=1;
        while(quf.size()!=0){
            if(quf.front()->left!=nullptr) quf.push(quf.front()->left);
            if(quf.front()->right!=nullptr) quf.push(quf.front()->right);
            res.push_back(quf.front()->val);
            quf.pop();
            count--;
            if(count==0){
                count=quf.size();
                vec.push_back(res);
                res={};
                
            }
        }
        return vec;
    }
};

//Solution 3
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<TreeNode*, int>> que;
        vector<vector<int>> res;
        que.push({root, 1});
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            if(temp.second>res.size()) res.push_back({});
            res[temp.second-1].push_back(temp.first->val);
            if(temp.first->left) que.push({temp.first->left, temp.second+1});
            if(temp.first->right) que.push({temp.first->right, temp.second+1});
        }
        return res;
    }
};

//Solution 4
class Solution {
private:
    void tra(TreeNode* root, vector<vector<int>>& res, int count){
        if(root){
            if(res.size()<count) res.push_back({});
            tra(root->left, res, count+1);
            res[count-1].push_back(root->val);
            tra(root->right, res, count+1);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        tra(root, res, 1);
        return res;
    }
};
