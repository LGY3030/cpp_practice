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
 //Solution 1, recurrsion
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec){
        if(root!=nullptr){
            inorder(root->left, vec);
            vec.push_back(root->val);
            inorder(root->right, vec);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return vector<int>{};
        vector<int> vec;
        inorder(root, vec);
        return vec;
    }
};


//Solution 2, stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> sta;
        while(root!=nullptr || sta.size()!=0){
            while(root!=nullptr){
                sta.push(root);
                root=root->left;
            }
            root=sta.top();
            vec.push_back(root->val);
            sta.pop();
            root=root->right;
        }
        return vec;
    }
};
