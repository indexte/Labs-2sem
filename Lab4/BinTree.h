#pragma once
#include<iostream>

using namespace std;

struct Node
{
	int x;
	Node *l, *r;
};

void add(int x, Node *&MyTree);
void del(Node *&Tree);
void printBinTree(Node *&Tree);