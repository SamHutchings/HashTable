// hashtableN0234219.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "table.h"


using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{


	

	HashTable<string> newTable;

	newTable.insert("One", "Chris");	
	newTable.insert("Two", "Bill");
	newTable.insert("Three", "Richard");
	newTable.insert("Four", "John");
	newTable.insert("Five", "Keith");
	newTable.insert("Six", "Peter");
	newTable.insert("Seven", "Mark");
	newTable.insert("Eight", "Andrew");
	newTable.insert("Nine", "Gary");
	newTable.insert("Ten", "Matthew");
	newTable.insert("Eleven", "Steve");
	newTable.insert("Twelve", "Chris");	
	newTable.insert("Thirteen", "Bill");
	newTable.insert("Fourteen", "Richard");
	newTable.insert("Fifteen", "John");
	newTable.insert("Sixteen", "Keith");
	newTable.insert("Seventeen", "Peter");
	newTable.insert("Eighteen", "Mark");
	newTable.insert("Nineteen", "Andrew");
	newTable.insert("Twenty", "Gary");
	newTable.insert("Twenty-One", "Matthew");
	newTable.insert("Twenty-Two", "Steve");
	newTable.insert("Twenty-Three", "Richard");
	newTable.insert("Twenty-Four", "John");
	newTable.insert("Twenty-Five", "Keith");
	newTable.insert("Twenty-Six", "Peter");
	newTable.insert("Twenty-Seven", "Mark");
	newTable.insert("Twenty-Eight", "Andrew");
	newTable.insert("Twenty-Nine", "Gary");
	newTable.insert("Thirty", "Matthew");

	newTable.viewStats();

	newTable.get("Twenty-Six");
	if(newTable.exists("Thirteen")) {
		cout << "Thirteen exists";
	}

	newTable.remove("One");
	newTable.remove("Two");
	newTable.remove("Three");
	newTable.remove("Four");
	newTable.remove("Five");
	newTable.remove("Six");
	newTable.remove("Seven");
	newTable.remove("Eight");
	newTable.remove("Nine");
	newTable.remove("Ten");
	newTable.remove("Eleven");
	newTable.remove("Twelve");
	newTable.remove("Thirteen");
	newTable.remove("Fourteen");
	newTable.remove("Fifteen");
	newTable.remove("Sixteen");
	newTable.remove("Seventeen");
	newTable.remove("Eighteen");
	newTable.remove("Nineteen");
	newTable.remove("Twenty");
	newTable.remove("Twenty-One");
	newTable.remove("Twenty-Two");

	newTable.viewStats();

	newTable.shrink();

	newTable.viewStats();
}

