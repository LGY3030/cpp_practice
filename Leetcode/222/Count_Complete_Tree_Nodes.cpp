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
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

//Solution 2
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=0, rh=0;
        TreeNode* leftr=root;
        TreeNode* rightr=root;
        while(leftr){
            leftr=leftr->left;
            lh++;
        }
        while(rightr){
            rightr=rightr->right;
            rh++;
        }
        if(lh==rh) return pow(2, lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

//Solution 3
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0; i<size; i++){
                TreeNode* temp=que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            res+=size;
        }
        return res;
    }
};
