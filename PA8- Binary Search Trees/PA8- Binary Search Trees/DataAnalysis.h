#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"

class DataAnalysis {
public:
	DataAnalysis();
	~DataAnalysis();
	void runAnalysis();
private:
	void loopFile();
	void splitFile(int &units, string &item, string &status);
	void compare(int &units, string &item, string &status);
	void printTrends();
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
};