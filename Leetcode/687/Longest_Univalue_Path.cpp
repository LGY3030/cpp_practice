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
private:
    int help(TreeNode* root, int& res){
        int l=0, r=0;
        if(root->left) l=help(root->left, res);
        if(root->right) r=help(root->right, res);
        if(root->left && root->left->val==root->val) l++;
        else l=0;
        if(root->right && root->right->val==root->val) r++;
        else r=0;
        res=max(res, l+r);
        return max(l, r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        help(root, res);
        return res;
    }
};
