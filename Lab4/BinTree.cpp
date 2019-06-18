#include"BinTree.h"

void add(int x, Node *&MyTree)	     //add item to tree
{
	if (NULL == MyTree)              //if the tree is empty
	{
		MyTree = new Node;           //allocate memory for new node
		MyTree->x = x;               //write data
		MyTree->l = MyTree->r = NULL;
	}

	if (x < MyTree->x)			     //if the entered element x < x element from the seed of the tree, move to the left
	{
		if (MyTree->l != NULL)
			add(x, MyTree->l);		 //with the help of recursion we push the element onto the free area.
		else
		{
			MyTree->l = new Node;
			MyTree->l->l = MyTree->l->r = NULL;
			MyTree->l->x = x;
		}
	}

	if (x > MyTree->x)               //if the entered element x > x element from the seed of the tree, move to the right
	{
		if (MyTree->r != NULL) 
			add(x, MyTree->r);
		else
		{
			MyTree->r = new Node;
			MyTree->r->l = MyTree->r->r = NULL;
			MyTree->r->x = x;
		}
	}
}

void del(Node *&Tree) {				 //tree delete function
	if (Tree != NULL)
	{
		del(Tree->l);                //recursive function on the left subtree
		del(Tree->r);                //recursive function on the right subtree
		delete Tree;                 //delete last element
	}

}

void printBinTree(Node *&Tree)       //tree print function
{
	if (Tree != NULL)
	{
		printBinTree(Tree->l);       //recursive function on the left subtree
		cout << Tree->x << '\t';     //show item
		printBinTree(Tree->r);       //recursive function on the right subtree
	}
}