/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(root->val>p->val) return root;
            root=root->right;
        }
        return nullptr;
    }
};

//Solution 2
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res=nullptr;
        while(root){
            if(root->val>p->val){
                res=root;
                root=root->left;
            }
            else root=root->right;
        }
        return res;
    }
};
