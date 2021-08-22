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
    void help(TreeNode* root, TreeNode* find, vector<TreeNode*>& vec){
        if(!root) return;
        if(root==find) vec.push_back(root);
        if(vec.size()>0 && vec[vec.size()-1]==find) return;
        vec.push_back(root);
        help(root->left, find, vec);
        help(root->right, find, vec);
        if(vec.size()>0 && vec[vec.size()-1]!=find) vec.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;
        help(root, p, pv);
        help(root, q, qv);
        TreeNode* res=nullptr;
        for(int i=0; i<min(qv.size(), pv.size()); i++){
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
        if(p->val<root->val && q->val<root->val) return lowestCommonAncestor(root->left, p, q);
        if(p->val>root->val && q->val>root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
