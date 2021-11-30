#include "Wordset.hpp"
#include <string>
 
const int BASE_TO_USE = 37;
const double LOAD_LIMIT = 0.25;
 
// returns s, as a number in the given base, mod the given modulus
int hashFunction(std::string s, int base, int mod)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
        sum *= base;
        sum = sum % mod;
 
        sum += s[i] - 'a';
    	sum = sum % mod;
	}
	return sum;
}
 
// constructor for WordSet hash table
// initialize wordArray w/ empty string
WordSet::WordSet()
{
	capacity = SIZES[0];
	wordArray = new std::string[capacity];
	for (int i = 0; i < capacity; i++)
	{
    	wordArray[i] = "";
	}
	sizesTracker = 0;
	wordNum = 0;
}
//destructor
WordSet::~WordSet()
{
	delete[] wordArray;
}
 
// insert s unless already contained
// if adding s exceeds load factor, immediately resize & readd elements
// use quad probing to find index
void WordSet::insert(std::string s)
{
	if (contains(s)) { return; }
	wordNum++;
 
	double percentLoaded = ((double)wordNum)/capacity;
 
	if (percentLoaded > LOAD_LIMIT) {
 
    	sizesTracker += 1;
 
    	int oldCapacity = capacity;
    	capacity = SIZES[sizesTracker];
    	std::string* oldWordArray = wordArray;
    	wordArray = new std::string[capacity];
    	wordNum = 0;
 
    	for (int i = 0; i < capacity; i++) { //initialize new string arr
            wordArray[i] = "";
    	}
 
    	for (int i = 0; i < oldCapacity; i++) { //copy words from old arr over
            if (oldWordArray[i] != "") {
                insert(oldWordArray[i]);
            }
    	}
    	delete[] oldWordArray;
	}
    
 
	int key = hashFunction(s, BASE_TO_USE, capacity);
	int i = 1;
	while (true) {
    	if (wordArray[key] == "") {
            wordArray[key] = s;
            break;
    	}
    	key = (key + i*i) % capacity;
    	i++;
	}
}
 
// search through key to (key + capacity^2)%capacity indices
bool WordSet::contains(std::string s) const
{
	int key = hashFunction(s, BASE_TO_USE, capacity);
	for (int i = 0; i <= capacity; i++) {
    	key = (key + i * i) % capacity;
    	if (wordArray[key] == "") {
            return false;
    	}
    	else if (wordArray[key] == s) {
            return true;
    	}
	}
	return false;
}
 
// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return wordNum;
}
 
// return how large the underlying array is.
int WordSet::getCapacity() const
{
	return capacity;
}
