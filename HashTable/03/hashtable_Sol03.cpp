// Author: Selcuk Orhan Demirel
// Date: 01/13/2011

// Test of HashTable Class

#include <iostream>
#include "hashtable.h"

using namespace std;

int main()
{

	HashTable ht;
	ht.add("first","Orhan");
	ht.add("second","Richie");
	ht.add("third","Stan");

	cout << ht.find("second") << endl;

	system("PAUSE");
	return 0;
}