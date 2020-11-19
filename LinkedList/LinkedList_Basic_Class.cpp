#include<iostream>

using namespace std;

class listnode{
	private:
		int data;
		listnode* next;
	public:
		listnode():data(0),next(0){};
		listnode(int a):data(a),next(0){};

	friend class linkedlist;
};

class linkedlist{
	private:
		listnode *first;
	public:
		linkedlist():first(0){};
		void printlist();
		void pushfront(int num);
		void pushback(int num);
		void deletenode(int num);
		void clear();
		void reverse();
};

void linkedlist::printlist(){
	if(first == 0){
		cout<<"This list is empty"<<endl;
		return;
	}
	listnode *current = first;
	while(current != 0){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<endl;
}

void linkedlist::pushfront(int num){
	listnode *current = new listnode(num);
	current->next = first;
	first = current;
}

void linkedlist::pushback(int num){
	listnode *current = new listnode(num);
	if(first == 0){
		first = current;
		return;
	}
	listnode *tmp = first;
	while(tmp->next!=NULL){
		tmp = tmp->next;
	}
	tmp->next = current;
}

void linkedlist::deletenode(int num){
	if(first == 0){
		cout<<"This list is empty"<<endl;
		return;
	}
	listnode *current = first;
	listnode *previous = 0;
	while(current!=0 && current->data!=num){ // order-> left to right
		previous = current;
		current = current->next;
	}
	if(current == 0){
		cout<<"There is no target in the list"<<endl;
	}
	else if(current == first){
		first = current->next;
		delete current; // only delete memory not pointer address, so needs next line
		current = 0; // https://blog.csdn.net/qq_36570733/article/details/80043321
	}
	else{
		previous->next = current->next;
		delete current;
		current = 0;
	}
}

void linkedlist::clear(){
	while(first!=0){
		listnode *current = first;
		first = first->next;
		delete current;
		current = 0;
	}
}

void linkedlist::reverse(){
	if(first == 0){
		cout<<"This list is empty"<<endl;
		return;
	}
	listnode *previous = 0;
	listnode *current = first;
	listnode *back = current->next;
	//if(next == 0) return;
	while(back!=0){
		current->next = previous;
		previous = current;
		current = back;
		back = back->next;
	}
	current->next = previous;
	first = current;
}

int main(){
	//test
	linkedlist list;
	list.printlist();
	list.pushfront(1);
	list.pushfront(2);
	list.printlist();
	list.pushfront(5);
	list.pushfront(4);
	list.printlist();
	list.pushback(8);
	list.printlist();
	list.deletenode(9);
	list.printlist();
	list.reverse();
	list.printlist();
	list.clear();
	list.printlist();
} 
