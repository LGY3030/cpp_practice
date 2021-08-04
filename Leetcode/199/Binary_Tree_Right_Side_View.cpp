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
private:
    int get(TreeNode* root){
        if(root==nullptr) return 0;
        return max(get(root->left),get(root->right))+1;
    }
    void count(TreeNode* root, int level, vector<vector<int>> &vec){
        if(root==nullptr) return;
        vec[level].push_back(root->val);
        if(root->left) count(root->left, level+1, vec);
        if(root->right) count(root->right, level+1, vec);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        int depth=get(root);
        vector<int> res;
        vector<vector<int>> vec(depth);
        count(root, 0, vec);
        for(auto &i:vec){
            res.push_back(i[i.size()-1]);
        }
        return res;
    }
};

//Solution 2
class Solution {
private:
    void count(TreeNode* root, int level, vector<int> &res){
        if(root==nullptr) return;
        if(res.size()<=level) res.push_back(root->val);
        if(root->right) count(root->right, level+1, res);
        if(root->left) count(root->left, level+1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        count(root, 0, res);
        return res;
    }
};

//Solution 3
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0; i<size; i++){
                TreeNode* temp=que.front();
                que.pop();
                if(i==0) res.push_back(temp->val);
                if(temp->right) que.push(temp->right);
                if(temp->left) que.push(temp->left);
            }
        }
        return res;
    }
};
