// Author: Selcuk Orhan Demirel
// Date: 01/13/2011

// Simple implementation of a HashTable in C++
// Uses an array of linklists to form a hashtable.

#include <string>
#include <list>	// link list
using namespace std;

#define SIZE 20

class Entry
{
public:
	string key;
	string value;
};

class HashTable
{
public:
	void add(string key, string value);
	string find(string key);
private:
	int hashFunc(string key);
	list<Entry> table[SIZE];
};

// adds a key-value pair to hash table
void HashTable::add(string key, string value)
{
	int val = hashFunc(key);
	Entry e;
	e.key = key;
	e.value = value;
	table[val].push_back(e);
}

// find a given key in hastable and return the associated value.
string HashTable::find(string key)
{
	int val = hashFunc(key);
	list<Entry>::iterator it;
	for(it = table[val].begin(); it != table[val].end(); it++)
	{
		if(it->key == key)
			return it->value;
	}
	return NULL;
}

// hash function
int HashTable::hashFunc(string key)
{
	int val = 0;
	for(int i=0; i<(int)key.length();i++)
	{
		int letter = key[i] - 96;
		val = ((val * 27) + letter) % SIZE; // using Horner's method
	}

	return val;
}