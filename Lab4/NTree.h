#pragma once
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct nNode
{
	int key;
	vector<nNode *> child;
};

nNode *newNode(int key);
void printNTree(nNode * root);
