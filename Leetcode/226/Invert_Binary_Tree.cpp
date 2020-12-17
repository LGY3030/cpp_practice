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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        if(root->left!=nullptr || root->right!=nullptr){
            TreeNode * tmp=root->left;
            root->left=root->right;
            root->right=tmp;
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};



 //Solution 2, Cleaner
 class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        TreeNode * tmp=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(tmp);
        return root;
    }
};
