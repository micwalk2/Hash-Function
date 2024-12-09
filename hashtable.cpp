#include "hashtable.h"

HashTable::HashTable(int keys)
{
	// Construct the HashTable object
	this->numKeys = keys;
	table = new std::list<std::string>[numKeys];
}

HashTable::~HashTable()
{
	// Free up the memory allocated for the HashTable object
	delete[] table;
}

void HashTable::InsertData(const std::string& data)
{
	// Hash the data to determine its key and insert it into the table
	int dataKey = HashKey(data);
	table[dataKey].push_back(data);
}

int HashTable::HashKey(const std::string& data)
{
	// Return the key for the hash table
	// Sum of the ASCII values modulo numKeys
	int hash = 0;
	for (char c : data)
	{
		hash += c;
	}
	return hash % this->numKeys;
}

void HashTable::DisplayHashTable()
{
	// Display the hash table
	for (int i = 0; i < numKeys; i++)
	{
		if (i < 10)
		{
			std::cout << i << ":  ";
		}
		else
		{
			std::cout << i << ": ";
		}
		
		for (auto& x : table[i])
		{
			std::cout << " --> " << x;
		}
		std::cout << "\n";
	}
}

bool HashTable::FindValue(const std::string& data)
{
	bool isFound = false;
	std::list<std::string>::iterator i;
	
	// Hash the data to determine the key
	int dataKey = HashKey(data);
	// Set the iterator to the beginning of the list
	i = table[dataKey].begin();

	while (!isFound && i != table[dataKey].end())
	{
		if (*i == data)
		{
			// If the data is found, return true
			return true;
		}
		else
		{
			// Increment the iterator
			i++;
		}
	}

	if (i != table[dataKey].end())
	{
		// Last value is what we are looking for
		return true;
	}
	else
	{
		return false;
	}
}

bool HashTable::DeleteData(const std::string& data)
{
	bool isFound = false;
	std::list<std::string>::iterator i;

	// Determine the key
	int dataKey = HashKey(data);
	// Set the iterator to the beginning of the list
	i = table[dataKey].begin();

	while (!isFound && i != table[dataKey].end())
	{
		if (*i == data)
		{
			// Set isFound to true
			isFound = true;
		}
		else
		{
			// Increment the iterator
			i++;
		}
	}

	if (i != table[dataKey].end())
	{
		// Delete the value
		table[dataKey].erase(i);
		return true;
	}
	else
	{
		return false;
	}
}