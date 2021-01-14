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
 //Solution 1, DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right!=nullptr) return 1+minDepth(root->right);
        if(root->left!=nullptr && root->right==nullptr) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};


//Solution 2, BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int res=0;
        while(que.size()!=0){
            res++;
            int k=que.size();
            for(int i=0;i<k;i++){
                TreeNode* tmp=que.front();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
                que.pop();
                if(!tmp->left && !tmp->right) return res;
            }  
        }
        return -1;
    }
};
