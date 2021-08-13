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
    bool help(TreeNode* root, TreeNode* sub){
        if(root==nullptr && sub==nullptr) return true;
        if(root==nullptr || sub==nullptr) return false;
        return root->val==sub->val && help(root->left, sub->left) && help(root->right, sub->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> sta;
        vector<TreeNode*> vec;
        sta.push(root);
        while(!sta.empty()){
            if(sta.top()->val==subRoot->val) vec.push_back(sta.top());
            TreeNode* temp=sta.top();
            sta.pop();
            if(temp->left) sta.push(temp->left);
            if(temp->right) sta.push(temp->right);
        }
        bool res=false;
        for(auto&i:vec) res|=help(i, subRoot);
        return res;
    }
};
