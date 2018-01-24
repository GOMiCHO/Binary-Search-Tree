#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "TransactionNode.h"

class BST {
public:
	BST();
	~BST();
	Node *getRoot();
	void setRoot(Node *nRoot);
	void insert(string nData, int nUnits);
	void inOrderTraversal();
	TransactionNode &findLargest();
	TransactionNode &findSmallest();
private:
	Node *mpRoot;
	void insert(Node *&pTree, string nData, int nUnits);
	void inOrderTraversal(TransactionNode *&pTree);
	void destroyTree(Node *&pTree);
};