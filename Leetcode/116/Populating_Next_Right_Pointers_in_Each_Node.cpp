/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//Solution 1
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0; i<size; i++){
                Node* temp=que.front();
                que.pop();
                if(i==size-1) temp->next=nullptr;
                else temp->next=que.front();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        return root;
    }
};

//Solution 2
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* res=root;
        while(root->left){
            Node* temp=root;
            while(temp){
                temp->left->next=temp->right;
                if(temp->next) temp->right->next=temp->next->left;
                temp=temp->next;
            }
            root=root->left;
        }  
        return res;
    }
};
