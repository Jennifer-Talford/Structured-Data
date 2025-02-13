#include <iostream>
// stores key-value pairs, where each key is unique and associated with a single value
#include <map>
// powerful tool for strings; allows you to perform various operations such as concatenation,search,and manip of text data (aka alter info)
#include <string>
// opens header file outside of main program
#include "yourHeader.h"
using namespace std;

int main()
{
	bool looper = false;
	int size = 10;
	int partcount = 0;
	string choice;
	string item;

	//Setting up pointer to use in Key Value Pair Map
	map <string, int>::iterator mapiterator;

	//Key Pair set up
	map <string, int> binmap;
	binmap.insert(pair<string, int >("Valve", 10));
	binmap.insert(pair<string, int >("Bearing", 5));
	binmap.insert(pair<string, int >("Bushing", 15));
	binmap.insert(pair<string, int >("Coupling", 21));
	binmap.insert(pair<string, int >("Flange", 7));
	binmap.insert(pair<string, int >("Gear", 5));
	binmap.insert(pair<string, int >("Gear Housing", 5));
	binmap.insert(pair<string, int >("Vacuum Gripper", 25));
	binmap.insert(pair<string, int >("Cable", 18));
	binmap.insert(pair<string, int >("Rod", 12));

	while (looper == false)
	{
		cout << "Part Type:                   " << "Number of Parts: " << endl;
		//Cycles through entire Key Value Pair map
		for (mapiterator = binmap.begin(); mapiterator != binmap.end(); mapiterator++)
		{
			cout << mapiterator->first << "                            " << mapiterator->second << endl;
		}
		//Lets user enter choice from menu
		cout << "Please select one of the following options, by typing in its corresponding number, to continue: " << endl;
		cout << "1. Add item" << endl << "2. Removed item" << endl << "3. Exit program" << endl;
		cin >> choice;

		//Checking user selection
		//This allows user to add amount from item selected
		if (choice == "1")
		{
			//Creating loop to check for valid input
			bool loop = true;

			cout << "Which item would you like to add to? Please type in name of item. " << endl;
			cin >> item;

			//Finding value from pointer map
			auto items = binmap.find(item);

			//Loop to check if value is valid
			if (items == binmap.end())
			{
				cout << "Not a valid choice." << endl;

				loop = false;
			}

			//Altering set value to user input value
			if (loop == true)
			{
				cout << "How many parts would you like to add? Maximum the bin can hold is 30." << endl;
				cin >> partcount;

				if (items->second < 30 && partcount > 0)
				{
					items->second += partcount;

					if (items->second > 30)
					{
						items->second = 30;
					}
				}
			}
		}

		//Allows user to subtract amount from item selected
		if (choice == "2")
		{
			//Creating loop to check for valid input
			bool loop2 = true;

			cout << "Which item would you like to remove from? Please type in name of item. " << endl;
			cin >> item;

			//Finding value from pointer map
			auto items = binmap.find(item);

			//Loop to check if value is valid
			if (items == binmap.end())
			{
				cout << "Not a valid choice." << endl;

				loop2 = false;
			}

			//Altering set value to user input value
			if (loop2 == true)
			{
				cout << "How many parts would you like to remove? Can remove down to 0." << endl;
				cin >> partcount;

				if (partcount > 0)
				{
					items->second -= partcount;
					if (items->second < 0)
					{
						items->second = 0;
					}
				}
			}
		}

		//Exits out of program per user choice
		if (choice == "3")
		{
			looper = true;
		}
	}
}
