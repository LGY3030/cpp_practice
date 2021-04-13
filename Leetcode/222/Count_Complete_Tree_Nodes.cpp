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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

//Solution 2
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=0, rh=0;
        TreeNode* leftr=root;
        TreeNode* rightr=root;
        while(leftr){
            leftr=leftr->left;
            lh++;
        }
        while(rightr){
            rightr=rightr->right;
            rh++;
        }
        if(lh==rh) return pow(2, lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
