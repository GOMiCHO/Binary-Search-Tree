#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"

class TransactionNode : public Node {
public:
	TransactionNode(int units = 0, string = "");
	~TransactionNode();
	int getUnits();
	void setUnits(int nUnits);
	void printData();	//Override
private:
	int mUnits;
};