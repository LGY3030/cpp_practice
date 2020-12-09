#include<iostream>

using namespace std;

struct Node{
	int data;
	Node * next;
};

void push_front(int, Node*&);
void push_end(int, Node*&);
void pop_front(Node*&);
void pop_end(Node*&);
void pop_index(int, Node*&);
void pop_num(int, Node*&);
void search(int, Node*&);
void reverse(Node*&);
void print_list(Node*);
 
int main(){
	Node * head = NULL;
	push_front(5, head);
	push_front(10,head);
	push_end(2,head);
	push_end(15,head);
	reverse(head);
	print_list(head);
} 

void push_front(int num, Node*& head){
	Node * current = new Node;
	current->data = num;
	current->next = head;
	head = current;
}

void push_end(int num, Node*& head){
	Node * current = new Node;
	current->data = num;
	current->next = NULL;
	Node * temp = head;
	if(head == NULL) head = current;
	else{
		while(temp->next!=NULL) temp=temp->next;
		temp->next = current;
	}
	
}

void pop_front(Node*& head){
	if(head == NULL){
		cout<<"The list is empty"<<endl;
	}
	else{
		Node * tmp = head;
		head = head->next;
	}
}

void pop_end(Node*& head){
	if(head == NULL){
		cout<<"The list is empty"<<endl;
	}
	else{
		Node * pre = NULL;
		Node * now = head;
		while(now->next != NULL){
			pre = now;
			now = now->next;
		}
		pre->next = NULL;
		delete now;
	}
}

void pop_index(int num, Node*& head){
	if(head==NULL) cout<<"The list is empty"<<endl;
	else{
		if(num<=0) cout<<"Out of index"<<endl;
		else if(num==1){
			Node * tmp = head;
			head = head->next;
			delete tmp;
		}
		else{
			Node * pre = NULL;
			Node * tmp = head;
			for(int i=1; i<num; i++){
				pre = tmp;
				tmp = tmp->next;
				if(tmp == NULL){
					cout<<"Out of index"<<endl;
					return;
				}
			}
			pre->next = tmp->next;
			delete tmp;
		}
	}
	
}

void pop_num(int num, Node*& head){	
	if(head == NULL) cout<<"The list is empty"<<endl;
	else{
		Node * pre = NULL;
		Node * tmp = head;
		int index = 0;
		while(tmp!=NULL){
			if(tmp->data == num){
				if(index == 0){
					head = tmp->next;
					delete tmp;
				}
				else{
					pre->next = tmp->next;
					delete tmp;
				}
				break;
			}
			pre = tmp;
			tmp = tmp->next;
			index++;
		}
	}
}

void search(int num, Node*& head){
	if(head == NULL) cout<<"The list is empty"<<endl;
	else{
		Node * tmp = head;
		while(tmp!=NULL){
			if(tmp->data==num){
				cout<<"Number is in the list"<<endl;
				break;
			}
			tmp = tmp->next;
		}
	}
}

void reverse(Node*& head){
	if(head == NULL) cout<<"The list id empty"<<endl;
	else if(head->next == NULL) return;
	else{
		Node * pre = NULL;
		Node * cur = head;
		Node * pos = head->next;
		while(pos!=NULL){
			cur->next = pre;
			pre = cur;
			cur = pos;
			pos = pos->next;
		}
		cur->next = pre;
		head = cur;
	}
	
}

void print_list(Node * head){
	Node * current = head;
	while(current!=NULL){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<endl;
}
