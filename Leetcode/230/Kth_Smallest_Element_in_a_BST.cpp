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
 //Solution 1, ��vector�s 
class Solution {
public:
    void tra(TreeNode* root, vector<int> &vec){
        if(root!=nullptr){
            tra(root->left, vec);
            vec.push_back(root->val);
            tra(root->right, vec);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        tra(root, vec);
        return vec.at(k-1);
    }
};


//Solution 2, ��count���覡 
class Solution {
public:
    void tra(TreeNode* root, int &k, int& res){
        if(root!=nullptr){
            tra(root->left, k, res);
            if(k==0) return;
            res=root->val;
            tra(root->right, --k, res);      
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        tra(root, k, res);
        return res;
    }
};
