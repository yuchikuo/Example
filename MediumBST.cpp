#include <iostream>
#include "string.h"
using namespace std;

// some random comments.

struct node{
	int value;
	int numChildren;
	node *leftChild, *rightChild, *parent;
};

class BST{
	public:
		// constructor
		BST();
		~BST();

		// interface
		void insert(int n);
		int getMedium(void);
		void printTree(void);
	private:
		node * root;
};

/** Implement Methods **/

BST::BST()
{
	root = NULL;
}

BST::insert(int n, BST & T){
	node *current = T->root;
	node *parent = NULL;
	// check if tree empty
	if(T->root == NULL)
	{
		T->root->value = n;
		T->root->parent = NULL;
	}
	else
	{
		while(current != NULL)	// traverse to correct position
		{
				parent = current;
				current = ( n < current->value)? current->leftChild : current->rightChild;
		}
		newChild = new struct node;
		newChild->value = n;
		if(n< parent->value)
		{
			parent->leftChild = newChild;
			newChild->parent = parent;
			parent->leftChild->leftChild = parent->rightChild->rightChild = NULL;
		}
		else
		{
			parent->rightChild = newChild;
			newChild->parent = parent;
			parent->leftChild->leftChild = parent->rightChild->rightChild = NULL;
		}
			
	}

}
void printTree(node *leaf){
	if(leaf != NULL)
	{
		if(leaf->leftChild != NULL)
			printTree(leaf->leftChild);
 		cout<< leaf->value + " ";
 		if(leaf->rightChild!= NULL)
 			printTree(leaf->rightChild);
	}
	else
		return;
}

int main(){
	BST bst = BST();

	char op;
	int n;
	while(op = getchar()){
		if(op == 'i')
		{
			cin >> n;
			insert(n, bst);
			printTree(bst->root);
		}
		else if(op == 'm')
		{
			printTree(bst->root);
			cout<<"Medium is : " + getMedium()<<endl;

		}
	}
	
}
