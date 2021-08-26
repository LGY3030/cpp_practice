/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* res=new Node(0);
        Node* cur=res;
        Node* temp=head;
        while(temp){
            Node* nn=new Node(temp->val);
            cur->next=nn;
            temp=temp->next;
            cur=cur->next;
        }
        res=res->next;
        cur=res;
        temp=head;
        Node* get=res;
        while(temp){
            Node* check=head;
            Node* store=temp->random;
            cur=res;
            while(check){
                if(check==store){
                    get->random=cur;
                    break;
                }
                check=check->next;
                cur=cur->next;
            }
            get=get->next;
            temp=temp->next;
        }
        return res;
    }
};
