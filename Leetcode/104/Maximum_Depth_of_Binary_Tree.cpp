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
    int cal(TreeNode* root, int count){
        if(root==nullptr) return count;
        count++;
        int count1 = cal(root->left, count);
        int count2 = cal(root->right, count);
        return max(count1, count2);
        
    }
    int maxDepth(TreeNode* root) {
        return cal(root, 0);
    }
};


//Solution 2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};
