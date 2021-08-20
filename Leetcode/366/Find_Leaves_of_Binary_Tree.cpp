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
    void help(TreeNode*& root, vector<int>& vec){
        if(root->left==nullptr && root->right==nullptr){
            vec.push_back(root->val);
            root=nullptr;
            return;
        }
        if(root->left) help(root->left, vec);
        if(root->right) help(root->right, vec);
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(root){
            vector<int> vec;
            help(root, vec);
            res.push_back(vec);
        }
        return res;
    }
};
