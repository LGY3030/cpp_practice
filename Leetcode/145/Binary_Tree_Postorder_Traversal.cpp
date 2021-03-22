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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        tra(root, res);
        return res;
    }
private:
    void tra(TreeNode* root, vector<int> &res){
        if(root==nullptr) return;
        tra(root->left, res);
        tra(root->right, res);
        res.push_back(root->val);
    }
};


//Solution 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()){
            root=sta.top();
            if(root->left==nullptr && root->right==nullptr){
                res.push_back(root->val);
                sta.pop();
            }
            if(root->right!=nullptr){
                sta.push(root->right);
                root->right=nullptr;
            }
            if(root->left!=nullptr){
                sta.push(root->left);
                root->left=nullptr;
            }
        }
        return res;
    }
};
