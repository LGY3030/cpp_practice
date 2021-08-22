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
private:
    void help(TreeNode* root, TreeNode* tn, vector<TreeNode*>& vec){
        if(!root) return;
        if(root==tn) vec.push_back(root);
        if(vec.size()>0 && vec[vec.size()-1]==tn) return;
        vec.push_back(root);
        help(root->left, tn, vec);
        help(root->right, tn, vec);
        if(vec.size()>0 && vec[vec.size()-1]!=tn) vec.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;
        help(root, p, pv);
        help(root, q, qv);
        TreeNode* res=nullptr;
        for(int i=0; i<min(pv.size(), qv.size()); i++){
            if(pv[i]==qv[i]) res=pv[i];
            else break;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q || !root) return root;
        TreeNode* left=lowestCommonAncestor(root->left, p ,q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        if(left&&right) return root;
        return left? left:right;
    }
};
