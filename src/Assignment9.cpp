/*


*/

#include<iostream>
#include<string>
#include<fstream>
#include"../include/HashTable.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[])
{
	HashTable* hash = new HashTable(10);

	std::ifstream in_file;	//might actually be useless.
	in_file.open(argv[1]);
	if (in_file.is_open())
	{
		//get shit done.
	}
	else
	{
		//nothing for now.
	}

	int select = 0;

	while (select != 6)
	{

		cout << "======Main Menu=====" << endl
			<< "1. Insert Movie" << endl
			<< "2. Delete Movie" << endl
			<< "3. Find Movie" << endl
			<< "4. Pritn Table of Contents" << endl
			<< "5. Quit" << endl;

		cin >> select;

		if (select == 1)	//Print Verticies
		{

		}

		if (select == 2)	//Find Districts
		{

		}

		if (select == 3)	//Find Shortest Path
		{

		}

		if (select == 4)	//Find Shortest Distance
		{

		}

		if (select == 5)	//Extra Credit
		{
			//
		}

		if (select == 6)	//Quit
			cout << "Goodbye!" << endl;
		if (select > 6)
			cout << "---That was not an option.---\n\n";
	}

	return 0;
}