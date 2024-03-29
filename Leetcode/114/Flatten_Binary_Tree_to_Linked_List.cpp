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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        while(root->right){
            root=root->right;
        }
        root->right=temp;
    }
};

//Solution 2
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left){
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=nullptr;
            while(root->right){
                root=root->right;
            }
            root->right=temp;
        }
    }
};

//Solution 3
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left && root->right){
                TreeNode* t=root->left;
                while(t->right) t=t->right;
                t->right=root->right;
            }
            if(root->left) root->right=root->left;
            root->left=nullptr;
            root=root->right;
        }
    }
};
