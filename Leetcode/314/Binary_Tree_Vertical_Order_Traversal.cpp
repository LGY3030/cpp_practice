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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==nullptr) return {};
        int minidx=0;
        queue<pair<TreeNode*, int>> que;
        map<int, vector<int>> umap;
        que.push({root, 0});
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            umap[temp.second].push_back(temp.first->val);
            if(temp.first->left) que.push({temp.first->left, temp.second-1});
            if(temp.first->right) que.push({temp.first->right, temp.second+1});
        }
        vector<vector<int>> vec;
        for(auto&i:umap) vec.push_back(i.second);
        return vec;
    }
};
