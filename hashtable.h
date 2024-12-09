#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

class HashTable
{
	int numKeys;
	std::list<std::string>* table;

public:
	HashTable(int keys);
	~HashTable();

	void InsertData(const std::string& data);
	int HashKey(const std::string& data);
	void DisplayHashTable();
	bool FindValue(const std::string& data);
	bool DeleteData(const std::string& data);
};