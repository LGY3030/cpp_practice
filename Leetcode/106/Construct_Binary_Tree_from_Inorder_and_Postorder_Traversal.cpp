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
    TreeNode* help(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend){
        if(inend<instart || postend<poststart) return nullptr;
        int inorderidx=instart;
        while(postorder[postend]!=inorder[inorderidx]) inorderidx++;
        TreeNode* root=new TreeNode(postorder[postend]);
        root->left=help(inorder, instart, inorderidx-1, postorder, poststart, poststart+(inorderidx-instart)-1);
        root->right=help(inorder, inorderidx+1, inend, postorder, poststart+(inorderidx-instart), postend-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
