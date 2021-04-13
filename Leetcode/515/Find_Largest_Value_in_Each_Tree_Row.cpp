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
    void compare(TreeNode* root, vector<int> &res, int level){
        if(root==nullptr) return;
        if(level>=res.size()) res.push_back(root->val);
        if(res[level] < root->val) res[level]=root->val;
        if(root->left) compare(root->left, res, level+1);
        if(root->right) compare(root->right, res, level+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        compare(root, res, 0);
        return res;
    }
};
