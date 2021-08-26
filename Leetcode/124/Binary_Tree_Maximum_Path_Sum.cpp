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
    int help(TreeNode* root, int& res){
        int l=0, r=0;
        if(root->left) l=help(root->left, res);
        if(root->right) r=help(root->right, res);
        res=max(res, max(r+l+root->val, max(root->val, max(l+root->val, r+root->val))));
        return max(max(l, r)+root->val, root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        help(root, res);
        return res;
    }
};

//Solution 2
class Solution {
private:
    int help(TreeNode* root, int& res){
        if(!root) return 0;
        int l=help(root->left, res);
        int r=help(root->right, res);
        if(l<0) l=0;
        if(r<0) r=0;
        res=max(res, l+r+root->val);
        return max(l, r)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        help(root, res);
        return res;
    }
};
