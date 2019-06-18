#include<iostream> 
#include<vector>
#include<queue>
#include"NTree.h"
#include"BinTree.h"

using namespace std;


int main()
{
	cout << "N-ary Tree:" << endl;

	nNode *root = newNode(1);		//create new tree with first item

	(root->child).push_back(newNode(2));
	(root->child).push_back(newNode(12));
	(root->child).push_back(newNode(63));
	(root->child).push_back(newNode(10));
	(root->child[0]->child).push_back(newNode(7));
	(root->child[0]->child).push_back(newNode(88));
	(root->child[2]->child).push_back(newNode(1));
	(root->child[3]->child).push_back(newNode(7));
	(root->child[3]->child).push_back(newNode(8));
	(root->child[3]->child).push_back(newNode(20));

	printNTree(root);

	cout << endl;

	cout << "Binary Tree:" << endl;

	Node *tree = NULL;
	add(1, tree);
	add(11, tree);
	add(5, tree);
	add(96, tree);
	add(8, tree);
	add(45, tree);
	add(34, tree);
	add(2, tree);
	add(7, tree);
	add(9, tree);

	printBinTree(tree);
	del(tree);

	cout << endl;

	return 0;
}