// Michael Walker
// 
// CSC382 - Data Structures and Algorithms
// Assignment 3: Hash Function

// Objective:
// Using C++, create a hash function that takes plain text and returns a hashed text.

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <list>
#include "hashtable.h"

int main()
{
	// This program will receive string inputs and determine where to place it in the hash table.
	// --------------------------------------------------------------------------------------------

	// Create two hash tables, one with a prime number of keys and one with a non-prime number of keys
	HashTable table(20);
    HashTable primeTable(23);

    // Array of 100 names
    std::string names[] = {
        "Alice", "Bob", "Charlie", "David", "Eve",
        "Frank", "Grace", "Hannah", "Ian", "Jack",
        "Kate", "Liam", "Megan", "Noah", "Olivia",
        "Paul", "Quinn", "Rachel", "Steve", "Tina",
        "Ursula", "Victor", "Wendy", "Xander", "Yolanda",
        "Zoe", "Aaron", "Beatrice", "Connor", "Diane",
        "Edward", "Fiona", "George", "Heather", "Isabel",
        "James", "Kylie", "Lance", "Mandy", "Nathan",
        "Opal", "Patrick", "Quincy", "Rita", "Samuel",
        "Tanya", "Umberto", "Vanessa", "William", "Xena",
        "Yara", "Zachary", "Amelia", "Brendan", "Cara",
        "Derek", "Elise", "Felix", "Gina", "Henry",
        "Ivy", "Jasper", "Kiera", "Luke", "Mila",
        "Nolan", "Ophelia", "Peyton", "Quinn", "Reese",
        "Sara", "Thomas", "Uma", "Vincent", "Willa",
        "Xavier", "Yvette", "Zander", "Aiden", "Bella",
        "Carlos", "Daisy", "Ethan", "Freya", "Gavin",
        "Holly", "Isaac", "Jade", "Kevin", "Lola",
        "Mason", "Nina", "Oscar", "Piper", "Quinn",
        "River", "Sophia", "Tyler", "Uma", "Violet"
    };

    // Time the insertion of names into the hash tables
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        table.InsertData(names[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time to insert into the hash table with non-prime keys: " << duration.count() << " microseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        primeTable.InsertData(names[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time to insert into the hash table with prime keys: " << duration.count() << " microseconds" << std::endl;

    // Display the hash table after inserting the names
    std::cout << "Hash Table after inserting names:\n";
    table.DisplayHashTable();

    std::cout << std::endl;

    // Find a name (e.g., "Charlie") in non-prime hash table
    start = std::chrono::high_resolution_clock::now();
    std::string nameToFind = "Charlie";
    if (table.FindValue(nameToFind)) 
    {
        std::cout << nameToFind << " was found in the hash table.\n";
    }
    else 
    {
        std::cout << nameToFind << " was not found in the hash table.\n";
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time to find " << nameToFind << " in the non-prime hash table: " << duration.count() << " microseconds" << std::endl;

    // Find a name (e.g., "Charlie") in prime hash table
    start = std::chrono::high_resolution_clock::now();
    if (primeTable.FindValue(nameToFind))
    {
        std::cout << nameToFind << " was found in the prime hash table.\n";
    }
    else
    {
        std::cout << nameToFind << " was not found in the prime hash table.\n";
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time to find " << nameToFind << " in the prime hash table: " << duration.count() << " microseconds" << std::endl;

    // Delete another name (e.g., "Eve") in the non-prime hash table
    start = std::chrono::high_resolution_clock::now();
    std::string nameToDelete = "Eve";
    if (table.DeleteData(nameToDelete)) 
    {
        std::cout << nameToDelete << " has been deleted from the hash table.\n";
    }
    else 
    {
        std::cout << nameToDelete << " was not found for deletion in the hash table.\n";
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time to delete " << nameToDelete << " in the non-prime hash table: " << duration.count() << " microseconds" << std::endl;

    // Delete another name (e.g., "Eve") in the prime hash table
    start = std::chrono::high_resolution_clock::now();
    if (primeTable.DeleteData(nameToDelete))
    {
        std::cout << nameToDelete << " has been deleted from the prime hash table.\n";
    }
    else
    {
        std::cout << nameToDelete << " has been deleted from the prime hash table.\n";
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time to delete " << nameToDelete << " in the prime hash table: " << duration.count() << " microseconds" << std::endl;

    // Display the hash table after operations to show changes
    std::cout << "\nHash Table after operations:\n";
    table.DisplayHashTable();

    return 0;
}