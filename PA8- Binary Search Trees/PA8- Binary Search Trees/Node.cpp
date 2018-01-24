#include "Node.h"

Node::Node(string data) {	///Constructor
	this->mData = data;	//Sets given Data with class Data
	this->mpLeft = nullptr;		//If no data passed in, initilize as NULL
	this->mpRight = nullptr;
	if (TEST)	///Initially for Testing if constructed successfully
		cout << "*NODE SUCCESSFULLY CONSTRUCTED." << endl;
}

Node::~Node() {	///Deconstructor
	if (TEST)	///Initially for Testing if deconstructed successfully
		cout << "*NODE SUCCESSFULLY DECONSTRUCTED." << endl;
}

string Node::getData() {	///Getter
	return this->mData;		//Returns Data from Node class
}

Node *& Node::getPrev() {	///Getter
	return this->mpLeft;	//Returns pLeft from Node class
}

Node *& Node::getNext() {	///Getter
	return this->mpRight;	//Returns pRight from Node class
}

void Node::setData(string const data) {		///Setter
	this->mData = data;		//Sets Data from Node class
}

void Node::setPrev(Node *const nLeft) {		///Setter
	this->mpLeft = nLeft;	//Sets pLeft from Node class
}

void Node::setNext(Node *const nRight) {	///Setter
	this->mpRight = nRight;	//Sets pRight from Node class
}