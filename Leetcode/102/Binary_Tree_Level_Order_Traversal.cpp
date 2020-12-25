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
