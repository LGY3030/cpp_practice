#include<iostream>
#include<string>
#include<queue>

using namespace std;

//all place in public -> not a good way
class treenode{
	public:
		string str;
		treenode *left;
		treenode *right;
		treenode *parent;
		
		treenode():str(""),left(0),right(0),parent(0){};
		treenode(string s):str(s),left(0),right(0),parent(0){};
		
	friend class binarytree;
};

class binarytree{
	public:
		treenode *root;
		
		binarytree():root(0){};
		binarytree(treenode *node):root(node){};
		
		void preorder(treenode *current); //root->left->right
		void inorder(treenode *current); //left->root->right
		void postorder(treenode *current); //left->right->root
		void levelorder();
		
		treenode* leftmost(treenode *current);
		treenode* rightmost(treenode *current);
		
		treenode* inorder_successor(treenode *current);
		treenode* inorder_predecessor(treenode *current);
		
		void inorder_by_parent(treenode *root);
		void inorder_reverse(treenode *root);
		
};

void binarytree::preorder(treenode *current){
	if(current){
		cout<<current->str<<" ";
		preorder(current->left);
		preorder(current->right);
	}
}

void binarytree::inorder(treenode *current){
	if(current){
		inorder(current->left);
		cout<<current->str<<" ";
		inorder(current->right);
	}
}

void binarytree::postorder(treenode *current){
	if(current){
		postorder(current->left);
		postorder(current->right);
		cout<<current->str<<" ";
	}
}

void binarytree::levelorder(){
	queue<treenode*> q;
	q.push(this->root);
	
	while(!q.empty()){
		treenode *current = q.front();
		q.pop();
		cout<<current->str<<" ";
		
		if(current->left != 0) q.push(current->left);
		if(current->right != 0) q.push(current->right);
	}
}

treenode *binarytree::leftmost(treenode *current){
	while(current->left != 0){
		current = current->left;
	}
	return current;
}

treenode *binarytree::rightmost(treenode *current){
	while(current->right != 0){
		current = current->right;
	}
	return current;
}

treenode *binarytree::inorder_successor(treenode *current){
	if(current->right != 0) return leftmost(current->right);
	
	treenode *successor = current->parent;
	while(successor != 0 && current == successor->right){
		current = successor;
		successor = successor->parent;
	}
	return successor;
	
}

treenode *binarytree::inorder_predecessor(treenode *current){
	if(current->left != 0) return rightmost(current->left);
	
	treenode *predecessor = current->parent;
	while(predecessor != 0 && current == predecessor->left){
		current = predecessor;
		predecessor = predecessor->parent;
	}
	return predecessor;
}

void binarytree::inorder_by_parent(treenode *root){
	treenode *current = leftmost(root);
	while(current){
		cout<<current->str<<" ";
		current = inorder_successor(current);
	}		
}

void binarytree::inorder_reverse(treenode *root){
	treenode *current = rightmost(root);
	while(current != 0){
		cout<<current->str<<" ";
		current = inorder_predecessor(current);
	}
}

int main(){
	
	//not a good way to create a tree
	treenode *nodeA = new treenode("A");
	treenode *nodeB = new treenode("B");
	treenode *nodeC = new treenode("C");
	treenode *nodeD = new treenode("D");
	treenode *nodeE = new treenode("E");
	treenode *nodeF = new treenode("F");
	treenode *nodeG = new treenode("G");
	treenode *nodeH = new treenode("H");
	treenode *nodeI = new treenode("I");
	
	nodeA->left = nodeB;
	nodeB->left = nodeD;
	nodeB->right = nodeE;
	nodeE->left = nodeG;
	nodeE->right = nodeH;
	nodeA->right = nodeC;
	nodeC->left = nodeF;
	nodeF->right = nodeI;
	
	nodeB->parent = nodeA;
	nodeD->parent = nodeB;
	nodeE->parent = nodeB;
	nodeG->parent = nodeE;
	nodeH->parent = nodeE;
	nodeC->parent = nodeA;
	nodeF->parent = nodeC;
	nodeI->parent = nodeF;
	
	binarytree T(nodeA);
	
	T.preorder(T.root);
	cout<<endl;
	T.inorder(T.root);
	cout<<endl;
	T.postorder(T.root);
	cout<<endl;
	T.levelorder();
	cout<<endl;
	T.inorder_by_parent(T.root);
	cout<<endl;
	T.inorder_reverse(T.root);
	cout<<endl;
} 
