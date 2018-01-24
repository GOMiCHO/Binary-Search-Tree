#include "DataAnalysis.h"

DataAnalysis::DataAnalysis() {	///Constructor
	mCsvStream.open("data.csv", std::ios::in);	//Opens File on start up
	if (TEST)				///Initially for Testing if constructed successfully
		cout << "*DATA-ANALYSIS SUCCESSFULLY CONSTRUCTED." << endl;
}

DataAnalysis::~DataAnalysis() {	///Deconstructor
	mCsvStream.close();		//Closes file when finsished
	if (TEST)				///Initially for Testing if deconstructed successfully
		cout << "*DATA-ANALYSIS SUCCESSFULLY DECONSTRUCTED." << endl;
}

void DataAnalysis::runAnalysis() {	///Runs Whole Program
	loopFile();		//"Loops" through all lines in file until end
	printTrends();	//Prints trends from Purchased & Sold Data
}

void DataAnalysis::loopFile() {	///"Loops" through all lines in file until end
	string item, status;
	char temp[50];
	int units;
	mCsvStream.getline(temp, 50, '\n');	//Skips labels/first line
	while (!mCsvStream.eof()) {				///Loops through file until end
		splitFile(units, item, status);	//"Splits" the Files
		compare(units, item, status);	//Compares & inserts into purchases/sold tree
	}
	cout << "\t___ PURCHASED TREE ___" << endl;
	mTreePurchased.inOrderTraversal();	//Prints contents of purchased tree
	cout << "\t_____ SOLD TREE ______" << endl;
	mTreeSold.inOrderTraversal();		//Prints contents of sold tree
}

void DataAnalysis::splitFile(int &units, string &item, string &status) {	///Reads Item, Units & Status individually
	char temp[50];	//Temporarily stores strings read
	mCsvStream.getline(temp, 50, ',');	//Reads units in as string
	units = atoi(temp);						///Converts String -> Int & Stores
	mCsvStream.getline(temp, 50, ',');	//Reads Item
	item = temp;							///Stores Item
	mCsvStream.getline(temp, 50, '\n');	//Reads Status
	status = temp;							///Stores Status
}

void DataAnalysis::compare(int &units, string &item, string &status) {	///Compares & Inserts based on "Status" of the item
	if (status == "Purchased")					///If is purchased
		mTreePurchased.insert(item, units);	//Inserts into purchased tree
	else										///If else, is Sold
		mTreeSold.insert(item, units);		//Inserts into sold tree
}

void DataAnalysis::printTrends() {	///Prints trends (Least/Most) of purchases & sold trees
	cout << "\t________ TRENDS ________" << endl;
	cout << "\t[----Most Purchased----]" << endl;
	mTreePurchased.findLargest().printData();		//Prints Most Purchases
	cout << "\t[----Least Purchased---]" << endl;
	mTreePurchased.findSmallest().printData();		//Prints Least Purchases
	cout << "\t[------Most Sold-------]" << endl;
	mTreeSold.findLargest().printData();			//Prints Most Sold
	cout << "\t[------Least Sold------]" << endl;
	mTreeSold.findSmallest().printData();			//Prints Least Sold
	cout << endl;
}