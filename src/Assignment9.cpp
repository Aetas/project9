/*
// Derek Prince
// Assignment 9
// Hashing Movies (Perfectly) 
// Just kidding.
// Still hashing though.
// 
*/

#ifndef H_TABLE_SIZE
#define H_TABLE_SIZE 53
#endif	//H_TABLE_SIZE


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
	HashTable* hash = new HashTable();

	std::ifstream in_file;	//might actually be useless.
	in_file.open(argv[1]);
	if (in_file.is_open())
	{
		int year;
		string title, buffer;
		while (!in_file.eof())
		{
			getline(in_file, buffer, ',');	//rating - ditch
			getline(in_file, buffer, ',');
			title = buffer;
			getline(in_file, buffer, ',');
			year = stoi(buffer);
			getline(in_file, buffer);		//quantity - ditch

			//add movie or hash then add
			
		}
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

		if (select == 1)	//Insert Movie
		{

		}

		if (select == 2)	//Delete Movie
		{

		}

		if (select == 3)	//Find Movie
		{

		}

		if (select == 4)	//Print Table of Contents
		{

		}

		if (select == 5)	//Quit
			cout << "Goodbye!" << endl;
		if (select > 5)
			cout << "---That was not an option.---\n\n";
	}

	return 0;
}