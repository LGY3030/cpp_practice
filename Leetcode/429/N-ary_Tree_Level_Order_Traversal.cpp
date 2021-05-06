/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<pair<Node*, int>> que;
        que.push(make_pair(root, 1));
        while(que.size()!=0){
            pair<Node*, int> tmp=que.front();
            que.pop();
            for(auto&i:tmp.first->children){
                que.push(make_pair(i, tmp.second+1));
            }
            if(tmp.second>res.size()) res.push_back({tmp.first->val});
            else res[tmp.second-1].push_back(tmp.first->val);
        }
        return res;
    }
};
