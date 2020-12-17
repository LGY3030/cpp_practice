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
    bool check(TreeNode* leftn, TreeNode* rightn){
        if(leftn==nullptr || rightn==nullptr) return leftn==rightn;
        else return leftn->val==rightn->val&&check(leftn->left, rightn->right)&&check(leftn->right, rightn->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return check(root->left, root->right);
    }
};
