#include"NTree.h"


nNode *newNode(int key)			//create new tree with first item
{
	nNode *temp = new nNode;
	temp->key = key;
	return temp;
}

void printNTree(nNode * root)
{
	if (root == NULL)
		return;


	queue<nNode *> q;			 //create a queue 
	q.push(root);				 //enqueue root  
	while (!q.empty())
	{
		int n = q.size();

		while (n > 0)			 //if this node has children 
		{
			nNode * p = q.front(); 								//dequeue an item from queue and print it 
			q.pop();
			cout << p->key << " ";

			for (int i = 0; i < p->child.size(); i++) 			// enqueue all children of the dequeued item 
				q.push(p->child[i]);
			n--;
		}

		cout << endl;			//print new line between two levels 
	}
}