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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()){
            root=sta.top();
            sta.pop();
            res.push_back(root->val);
            if(root->right!=nullptr) sta.push(root->right);
            if(root->left!=nullptr) sta.push(root->left);
        }
        return res;
    }
};
