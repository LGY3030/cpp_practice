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
 //Solution 1, 存到vector比較 
class Solution {
public:
    void tra(TreeNode* t, vector<int> &vec){
        if(t!=nullptr){
            if(t->left!=nullptr) vec.push_back(1);
            else vec.push_back(0);
            if(t->right!=nullptr) vec.push_back(1);
            else vec.push_back(0);
            vec.push_back(t->val);
            tra(t->left, vec);
            tra(t->right, vec);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> forp;
        vector<int> forq;
        tra(p, forp);
        tra(q, forq);
        if(forp==forq) return true;
        return false;
    }
};


//Solution 2, 直接用遞迴比較每層的node, 直到其中一棵樹為null則回傳
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr) return p==q;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}; 
