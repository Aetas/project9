#include<iostream>
#include<fstream>
#include"../include/HashTable.h"

HashTable::HashTable()
{
	size = 0;
	hashTable = new Movie*[H_TABLE_SIZE];
	for (int i = 0; i < H_TABLE_SIZE; i++)
		hashTable[i] = nullptr;
}

HashTable::HashTable(int& table_size)
{
	size = 0;
	hashTable = new Movie*[table_size];
	for (int i = 0; i < table_size; i++)
		hashTable[i] = nullptr;
}

HashTable::~HashTable()
{
	delete[]hashTable;
}

void HashTable::printInventory()
{
	for (int i = 0; i < size; i++)
	{
		if (hashTable[i] = nullptr)
			continue;	//skip rest
		//cout shit
	}
}

void HashTable::insertMovie(std::string& in_title, int& in_year)
{
	int key = get_hash_key(in_title);
	if (hashTable[key] != nullptr)
		collision_resolution(in_title, in_year, key);
	else
	{
		Movie* temp = new Movie(in_title, in_year);
		hashTable[key] = temp;
	}
	size++;
}

void HashTable::deleteMovie(std::string& in_title)
{
	int key = get_hash_key(in_title);
	delete hashTable[key];
	hashTable[key] = nullptr;
	size--;
}

void HashTable::collision_resolution(std::string& in_title, int& in_year, int& key)
{
	Movie* new_movie = new Movie(in_title, in_year);
	Movie* it = hashTable[key]->next;
	while (it->next != nullptr)
		it = it->next;
	it->next = new_movie;
}

Movie* HashTable::findMovie(std::string& in_title)
{
	int key = get_hash_key(in_title);
	Movie* ans = hashTable[key];
	if (ans == nullptr)	//if the index has no movie - it is not in the table
		return nullptr;
	if (hashTable[key]->title != in_title)
	while ((ans->title != in_title) && (ans != nullptr))	//also takes care of the case where the index is taken, but the movie does not exist
			ans = ans->next;

	return ans;	//at this point, ans either holds the answer the function call came for, or nullptr, which is the default case for not found
}

unsigned int HashTable::get_size()
{
	return size;
}

bool HashTable::is_empty()
{
	if (size > 0)
		return false;
	return true;
}

int HashTable::get_hash_key(std::string& in_title)
{
	int sum = 0;
	for (std::string::iterator it = in_title.begin(); it != in_title.end(); it++)
		sum += *it;	//sum ASCII

	return (sum % H_TABLE_SIZE);	//at this point, I've forgone the idea of adding extra baggage to let user redefine the size, 
									//because that happens before the compiler runs anyhow, so changing the macro is just as easy, if not easier
									//the other option is table_size, which would hold the table size passed to the constructor just for hash key use
									//the main reason I cared about a simple 8 bytes floating around my class is not because of the space, but because
									//unsigned int would be the correct choice (*one of many) for holding a size, while plain int would be plain stupid.
									//the reason being, is that the entire idea of giving a choice of table size from runtime is that the user could use it for any size
									//and any size is a rather large number. So rather than a hack job, I chose to cut the weight and use a compiler macro for that silky smooth action. nns.
}
