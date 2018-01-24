#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define TEST false	//Used to test if everything worked initially (Is not needed)

class Node {
public:
	Node(string data = "");
	virtual ~Node();
	string getData();
	Node *& getPrev();
	Node *& getNext();
	void setData(string const data);
	void setPrev(Node *const nLeft);
	void setNext(Node *const nRight);
	virtual void printData() = 0;
protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};