#include "BST.h"

BST::BST() {	///Constructor
	this->mpRoot = nullptr;
	if (TEST)	///Initially for Testing if constructed successfully
		cout << "*BST SUCCESSFULLY CONSTRUCTED." << endl;
}

BST::~BST() {	///Deconstructor
	destroyTree(mpRoot);	//Destroys whole tree when finished
	if (TEST)	///Initially for Testing if deconstructed successfully
		cout << "*BST SUCCESSFULLY DECONSTRUCTED." << endl;
}

Node * BST::getRoot() {	///Getter
	return this->mpRoot;	//Returns mpRoot from BST class
}

void BST::setRoot(Node *nRoot) {	///Setter
	this->mpRoot = nRoot;	//Sets mpRoot from BST class
}

void BST::insert(string nData, int nUnits) {	///Base to insert recursion
	insert(*&mpRoot, nData, nUnits);	//Begins insertion recursion
}

void BST::inOrderTraversal() {	///Base to traversal recursion
	inOrderTraversal((TransactionNode *&)mpRoot);	//Begins traversal recursion
	cout << endl;
}

TransactionNode & BST::findLargest() {	///Finds largest units
	Node *pCur = mpRoot;
	while (pCur->getNext() != nullptr)	//Goes to furthest right to find largest value
		pCur = pCur->getNext();
	return *(dynamic_cast <TransactionNode*>(pCur));	//Casts node -> transactionNode
}

TransactionNode & BST::findSmallest() {	///Finds smallest units
	Node *pCur = mpRoot;
	while (pCur->getPrev() != nullptr)	//Goes to furthest left to find smallest value
		pCur = pCur->getPrev();
	return *(dynamic_cast <TransactionNode*>(pCur));	//Casts node -> transactionNode
}

void BST::insert(Node *&pTree, string nData, int nUnits) {	///Inserts into tree recursively
	if (pTree == nullptr)											///If node is empty
		pTree = new TransactionNode(nUnits, nData);				//Inserts into tree if null
	else if (nUnits < ((TransactionNode*)pTree)->getUnits())		///If left node is not empty
		insert(((TransactionNode*)pTree)->getPrev(), nData, nUnits);	//Go down left branch
	else if (nUnits > ((TransactionNode*)pTree)->getUnits())			///If right node is not empty
		insert(((TransactionNode*)pTree)->getNext(), nData, nUnits);	//Go down right branch
}

void BST::inOrderTraversal(TransactionNode *&pTree) {	///Prints everything from tree
	if (pTree != nullptr) {	///Goes down tree, prints everything from left to right
		inOrderTraversal((TransactionNode *&)pTree->getPrev());	//Travels through left branch
		pTree->printData();		//Prints data
		inOrderTraversal((TransactionNode *&)pTree->getNext());	//Travels through right branch
	}
}

void BST::destroyTree(Node *&pTree) {	///Destroys whole tree
	if (pTree != nullptr) {	///Loops through tree while not empty
		destroyTree(pTree->getPrev());	//Destroys left left
		destroyTree(pTree->getNext());	//Destroys right side
		delete pTree;	//Destroys current node once existing branches are destroyed
	}
}