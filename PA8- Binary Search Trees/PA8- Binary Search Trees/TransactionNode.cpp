#include "TransactionNode.h"

TransactionNode::TransactionNode(int units, string newData) : Node(newData) {	///Constructor
	this->mUnits = units;
	if (TEST)	///Initially for Testing if constructed successfully
		cout << "*TRANSACTION-NODE SUCCESSFULLY CONSTRUCTED." << endl;
}

TransactionNode::~TransactionNode() {	///Deconstructor
	if (TEST)	///Initially for Testing if deconstructed successfully
		cout << "*TRANSACTION-NODE SUCCESSFULLY DECONSTRUCTED." << endl;
}

int TransactionNode::getUnits() {	///Getter
	return this->mUnits;	//Returns Units from TransactionNode class
}

void TransactionNode::setUnits(int nUnits) {	///Setter
	this->mUnits = nUnits;	//Sets Units from TransactionNode class
}

void TransactionNode::printData(void) {	///Overrides printData() from Node class & prints data & units
	cout << "*ITEM: " << mData << " \t";	//Prints Data
	if (mData.length() < 8)					//Will indent to keep Units column aligned
		cout << "\t";
	cout << "*UNITS: " << mUnits << endl;	//Prints Units
}